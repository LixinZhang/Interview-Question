#include<iostream>
#include<cmath>
using namespace std;
#ifndef BUILDTREE
#define BUILDTREE

struct treenode {
    int value ;
    treenode * left;
    treenode * right;
    treenode(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};


treenode * treenodelist [20];

treenode * build_A_Test_Tree(){
    int arr[][2] = {
        {1,2},
        {3,4},
        {5,-1},
        {6,7},
        {-1,-1},
        {8,9},
        {-1,-1},
        {10,11},
        {-1,-1},
        {12,13},
        {14,-1},
        {15,16},
        {-1,-1},
        {-1,-1},
        {-1,-1},
        {-1,-1},
        {-1,-1}
    };
    /*
     * The tree is for test. Like following:
     *                           0
     *                        /     \
     *                       1       2
     *                      / \     /   
     *                     3   4   5
     *                    / \     / \
     *                   6   7   8   9
     *                      / \     / \
     *                     10 11   12 13
     *                    /  /  \
     *                   14  15 16
     */
    int n_nodes = 17;
    for(int i=0; i<n_nodes; i++){
        treenodelist[i] = new treenode(i);
    }
    for(int i=0;i<n_nodes; i++){
        if(arr[i][0] != -1){
            treenodelist[i]->left = treenodelist[arr[i][0]];
        }else{
            treenodelist[i]->left = NULL;
        }
        if(arr[i][1] != -1){
            treenodelist[i]->right = treenodelist[arr[i][1]];
        }else{
            treenodelist[i]->right = NULL;
        }
   }
    return treenodelist[0];
}

void scanTree(treenode * tnode){
    if(tnode == NULL) return ;
    cout<<tnode->value<<endl;
    scanTree(tnode->left);
    scanTree(tnode->right);
}

void printTestTree(){
    for(int i=0;i<17;i++){
        cout<<treenodelist[i]->value<<"\t";
        if(treenodelist[i]->left != NULL) cout<<treenodelist[i]->left->value<<"\t";
        else cout<<"NULL\t";
        if(treenodelist[i]->right != NULL) cout<<treenodelist[i]->right->value<<"\t";
        else cout<<"NULL\t";
        cout<<endl;
    }
}


int treeheight(treenode * tnode){
    if (tnode == NULL) return 0;
    int l = treeheight(tnode->left);
    int r = treeheight(tnode->right);
    return max(l,r) + 1;
}

#endif
