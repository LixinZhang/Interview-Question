/*
 * Chapter 2.2 
 * Question: Implement an algorithm to find nth to last element of a singly linked list.
 * 实现一个算法找到倒数第n个元素
 */

#include<iostream>
using namespace std;

struct node{
    int value;
    node * next;
    node(int v){
        value = v;
    }
};

void printlink(node * head){
    while(head != NULL){
        cout<<head->value<<"\t";
        head = head->next;
    }
    cout<<endl;
}

node * createTestLink(){
    node * head = new node(2);
    node * p = head;
    int arr[] = {1,3,1,5,3,7,3,3,5,5,6,4,4,5,4};
    int length = sizeof(arr) / sizeof(int);
    for(int i=0; i<length ;i++){
        p->next = new node(arr[i]);
        p = p->next;
    }
    return head;
}
/*
 * 设置两个节点指针，第一个先走n步，然后两个一起走，知道第一个到达终点后，第二个所指即为所求。
 */

node * solution(node * head, int n){
    node * pre = head;
    while(n>0){
        pre = pre->next;
        n--;
    }
    node * res = head;
    while(pre!=NULL){
        pre = pre->next;
        res = res->next;
    }
    return res;
} 

int main(){
    node * head = createTestLink();
    printlink(head);
    node * res = solution(head,2);
    cout<<res->value<<endl;
    return 0;
}
