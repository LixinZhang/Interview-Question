/*
 * Chapter 2.1
 * Question:Write code to remove duplicates from an unsorted linked list
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 * 从一个无序的链表中移除重复的元素
 * 如果不允许使用额外的临时空间，该如何进行呢？
 */

#include<iostream>
#include<set>
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

node * solution(node * head){
    if (head == NULL) return NULL;
    set<int> valueset;
    node * pre = head;
    node * p = pre->next;
    while(p != NULL){
        if(valueset.count(p->value) == 0){
            valueset.insert(p->value);
            pre = p;
            p = p->next;
        }
        else{
            pre->next = p->next;
            p = p->next;
        }
    }
    return head;
}


int main()
{
    node * head = new node(2);
    node * p = head;
    int arr[] = {1,3,1,5,3,7,3,3,5,5,6,4,4,5,4};
    int length = sizeof(arr) / sizeof(int);
    for(int i=0; i<length ;i++){
        p->next = new node(arr[i]);
        p = p->next;
    }
    printlink(head);
    head = solution(head);
    printlink(head);
    return 0;
}
