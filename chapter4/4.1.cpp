/*
 * Chapter 4.1
 * Implement a function to check if a tree is balanced. For the purposes of this question,
 * a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
 * from the root by more than one.
 * 实现一个函数用于检查一棵树是否是平衡的。平衡的定义是，两个叶子节点的高度相差不超过1.
 */
#include<iostream>
#include<cmath>
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
 * 递归求解每棵子树的高度，递归过程中进行平衡性的判断
 */

static bool isbalanced = true;
int checkBalanced(node * n){
    if (n == NULL) return 0;
    int lheight = checkBalanced(n->left);
    int rheight = checkBalanced(n->right);
    if (abs(lheight - rheight) > 1) isbalanced = false;
    return max(lheight,rheight) + 1;
}

bool isBalanced(node * head){
    isbalanced = true;
    checkBalanced(head);
    return isbalanced;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    node * head = NULL;
    head = buildtree(arr,0,sizeof(arr)/sizeof(int) - 1);
    cout<<isBalanced(head)<<endl;
    return 0;
}
