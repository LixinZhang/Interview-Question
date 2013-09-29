/*
 * Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
 写一个算法由一个有序的数组创建一个具有最小高度的二叉树
 */

#include<iostream>
using namespace std;
struct node {
    int value;
    node * left;
    node * right;
    node(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};

node * buildtree(int arr[], int low, int high){
    if(low > high) return NULL;
    int mid = (low + high) / 2;
    node * n = new node(arr[mid]);
    n->left = buildtree(arr,low, mid-1);
    n->right = buildtree(arr,mid+1,high);
    return n;
}

void scantree(node * head){
    if(head == NULL) return;
    cout<<head->value<<endl;
    scantree(head->left);
    scantree(head->right);
}
/*
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    node * head = NULL;
    head = buildtree(arr,0,sizeof(arr)/sizeof(int) - 1);
    scantree(head);
    return 0;
}*/
