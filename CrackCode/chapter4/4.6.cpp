/*
 * Design an algorithm and write code to find the first common ancestor of two nodes 
 * in a binary tree. Avoid storing additional nodes in a data structure. Note: This
 * is not necessarily a binary search tree.
 * 在一棵二叉树中找到两个节点的第一个公共祖先
 */

#include<iostream>
#include"buildtree.h"
using namespace std;

bool contains(treenode * tnode, treenode * node){
    if (tnode == NULL) return false;
    if (tnode == node) return true;
    return contains(tnode->left, node) || contains(tnode->right, node);
}

treenode * firstCommonAncestor(treenode * tnode, treenode * node1 , treenode * node2){
    bool l_node1 = contains(tnode->left,node1);
    bool r_node1 = contains(tnode->right,node1);
    bool l_node2 = contains(tnode->left,node2);
    bool r_node2 = contains(tnode->right,node2);
    if((l_node1 && r_node2) || (l_node2 && r_node1)) return tnode;
    if(l_node1 && l_node2) return firstCommonAncestor(tnode->left, node1, node2);
    if(r_node2 && r_node2) return firstCommonAncestor(tnode->right, node1, node2);
    return NULL;    
}

int main(){
    treenode * tnode = build_A_Test_Tree();
    cout<<treeheight(tnode)<<endl;
    treenode * ancestor = firstCommonAncestor(tnode, treenodelist[6], treenodelist[4]);
    if (ancestor == NULL) cout<<"Not find"<<endl;
    else cout<<ancestor->value<<endl;
    return 0;
}

