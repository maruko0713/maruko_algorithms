//
//  1114.cpp
//  算法
//
//  Created by 王怡凡 on 2017/9/8.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int n;
int mem[maxn],father[maxn],visit[10010],hashes[10010];

struct Fam {
    int id,father,mother,child[5],estate,area;
    
}fam[maxn];

void init() {
    for(int i=0;i<10010;i++) {
        father[i] = i;
    }
}

struct Ans {
    int id,num;
    double estate,area;
    bool flag;
}ans[10010];

bool cmp(Ans a, Ans b) {
    if(a.area!=b.area) {
        return a.area>b.area;
    }
    return a.id<b.id;
}

int findFather(int x) {
    int a=x;
    while(x!=father[x]) {
        x=father[x];
    }
    int z;
    while(a!=father[a]) {
        z=a;
        a=father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a,int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA>faB) {
        father[faA] = faB;
    } else {
        father[faB] = faA;
    }
}

int main() {
    scanf("%d",&n);
    init();
    int i,id1,id2,id3;
    for(i=0;i<n;i++) {
        scanf("%d%d%d",&id1,&id2,&id3);
        visit[id1] = 1;
        if(id2!=-1) {
            visit[id2] = 1;
            Union(id1,id2);
        }
        if(id3!=-1){
            visit[id3] = 1;
            Union(id1,id3);
        }
        fam[i].id=id1;
        fam[i].father= id2;
        fam[i].mother=id3;
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            scanf("%d",&fam[i].child[j]);
            visit[fam[i].child[j]] =1;
            Union(fam[i].child[j],id1);
        }
        scanf("%d%d",&fam[i].estate,&fam[i].area);
    }
    for(i=0;i<n;i++) {
        int id = findFather(fam[i].id);
        ans[id].id = id;
        ans[id].estate += fam[i].estate;
        ans[id].area += fam[i].area;
        ans[id].flag = true;
    }
    int cnt=0;
    for(i=0;i<10010;i++) {
        if(visit[i]==1) {
           int id = findFather(i);
            ans[id].num++;
            if(ans[id].flag&&hashes[id]==0) {
                hashes[id]=1;
                cnt++;
            }
        }
    }
    for(i=0;i<10010;i++) {
        if(ans[i].flag) {
            ans[i].area /= ans[i].num;
            ans[i].estate/=ans[i].num;
        }
    }
    printf("%d\n",cnt);
    sort(ans,ans+10010,cmp);
    for(i=0;i<cnt;i++) {
        printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].num,ans[i].estate,ans[i].area);
    }
    return 0;
}
