//
//  1043.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/28.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>

using namespace std;

vector<int> origin,pre,preM,post,postM;

struct node{
    int data;
    node *left, *right;
};

void insert(node* &root, int data) {
    if(root==NULL) {
        root = new node;
        root -> data = data;
        root -> left = NULL;
        root -> right = NULL;
        return ;
    }
    if(data<root->data) {
        insert(root->left,data);
    } else {
        insert(root->right, data);
    }
}

void preOrder(node* root, vector<int>& vi) {
    if(root==NULL) {
        return ;
    }
    vi.push_back(root->data);
    preOrder(root->left,vi);
    preOrder(root->right,vi);
}

void preOrderMirror(node* root, vector<int>& vi) {
    if(root==NULL) {
        return ;
    }
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node* root, vector<int>& vi) {
    if(root==NULL) {
        return ;
    }
    postOrder(root->left,vi);
    postOrder(root->right,vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int>& vi) {
    if(root==NULL) {
        return ;
    }
    postOrderMirror(root->right,vi);
    postOrderMirror(root->left,vi);
    vi.push_back(root->data);
}

int main() {
    int i,n,data;
    node* root = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&data);
        origin.push_back(data);
        insert(root,data);
    }
    preOrder(root,pre);
    preOrderMirror(root,preM);
    postOrder(root,post);
    postOrderMirror(root,postM);
    if(origin==pre) {
        printf("YES\n");
        for(i=0;i<post.size();i++) {
            printf("%d",post[i]);
            if(i<post.size()-1) {
                printf(" ");
            }
        }
    } else if(origin == preM) {
        printf("YES\n");
        for(i=0;i<postM.size();i++) {
            printf("%d",postM[i]);
            if(i<post.size()-1) {
                printf(" ");
            }
        }
    } else {
        printf("No\n");
    }
    return 0;
}