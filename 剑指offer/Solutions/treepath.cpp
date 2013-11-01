#include <iostream>
#include <vector>
#include "buildtree.h"
using namespace std;

'''
打印满足某一值的路径
'''


void treepath(treenode * root, int & cur_val, int path[], int uppon){
    if (root->left == NULL && root->right == NULL){
       cout<<cur_val + root->value<<endl;
       for(int i=0; i<uppon; i++)
           cout<<path[i]<<"\t";
       cout<<root->value<<endl;
    }
    if (root->left != NULL) {
        cur_val += root->value;
        path[uppon++] = root->value;
        treepath(root->left, cur_val, path, uppon);
        uppon --;
        cur_val -= root->value;
    }
    if (root->right != NULL) {
        cur_val += root->value;
        path[uppon++] = root->value;
        treepath(root->right, cur_val, path, uppon);
        uppon --;
        cur_val -= root->value;
    }
}

int main(){
    treenode * root = build_A_Test_Tree();
    int value = root->value;
    int path[100];
    int uppon = 0;
    treepath(root, value, path, uppon);
    return 0;
}
