//
//  1110.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 30;
int n,last;
bool flag = true;

struct Node {
    int left,right;
}node[maxn];
int isroot[maxn];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    int num=1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(num==n) {
            last = now;
        }
        if(node[now].left!=-1) {
            q.push(node[now].left);
            num++;
        } else if(num!=n) {
            flag = false;
        }
        if(node[now].right!=-1) {
             q.push(node[now].right);
            num++;
        } else if(num!=n) {
            flag = false;
        }
    }
    return;
}

int main() {
    scanf("%d",&n);
    int i;
    char left[3],right[3];
    memset(isroot,1,sizeof(isroot));
    for(i=0;i<n;i++) {
        getchar();
        scanf("%s %s",left,right);
//        printf("%s %s\n",left,right);
        if(left[0]=='-') {
            node[i].left = -1;
        } else {
            if(strlen(left)==1) {
                node[i].left = left[0] - '0';
            } else if(strlen(left)==2) {
                node[i].left = (left[0] - '0')*10+(left[1]-'0');
            }
            isroot[node[i].left] = 0;
//            printf("left: %d",node[i].left);
        }
        if(right[0]=='-') {
            node[i].right = -1;
        } else {
            if(strlen(right)==1) {
                node[i].right = right[0] - '0';
            } else if(strlen(right)==2) {
                node[i].right = (right[0] - '0')*10+(right[1]-'0');
            }
            isroot[node[i].right] = 0;
//            printf("right: %d\n",node[i].right);
        }
    }
    int root=0;
    for(i=0;i<n;i++) {
        if(isroot[i]) {
            root = i;
            break;
        }
    }
    bfs(root);
    if(flag) {
        printf("YES %d",last);
    } else {
        printf("NO %d",root);
    }
    return 0;
}
