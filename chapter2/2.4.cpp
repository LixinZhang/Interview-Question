/*
 * Chapter 2.4
 * Question:You have two numbers represented by linked list, where each node contains a single digit.
 * The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
 * Write a function tha adds the two numbers and returns  the sum as a linked list.
 * Example:
 * Input:(3->1->5) + (5->9->2)
 * Output: 8->0->8
 * 用链表表示的数字（数位的顺序相反），写一个函数用来将两个数字相加求和后返回一个链表
 */

#include<iostream>
using namespace std;

struct node {
    short digit;
    node * next;
    node(short _digit){
        digit = _digit;
        next = NULL;
    }
};
node * constructLink(short s[], int len){
    node * head = new node(s[0]);
    node * p = head;
    for(int i=1; i<len; i++){
        head->next = new node(s[i]);
        head = head->next;
    }
    return p;
}

/*
 * 说白了，这题就是用链表结构实现高精度加法
 * 原来教科书上写的大多用的是数组的形式，这个只不过时变了个存储形式
 */
node * solution_add(node * l1, node * l2){
    node * res = new node(0);
    node * head = res;
    short mod_v=0, div_v=0;
    while(l1!=NULL && l2!=NULL){
        mod_v = (l1->digit + l2->digit + div_v) % 10;
        res->next = new node(mod_v);
        div_v = (l1->digit + l2->digit + div_v) / 10;
        res = res->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL){
        mod_v = (l1->digit + div_v) % 10;
        res->next = new node(mod_v);
        div_v = (l1->digit + div_v) / 10;
        res = res->next;
        l1 = l1->next;
    }
    while(l2 != NULL){
        mod_v = (l2->digit + div_v) % 10;
        res->next = new node(mod_v);
        div_v = (l2->digit + div_v) / 10;
        res = res->next;
        l2 = l2->next;
    }

    if(div_v > 0)
        res->next = new node(div_v);
    return head->next;
}

void printlink(node * head){
    while(head != NULL){
        cout<<head->digit<<"\t";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    short s1 [] = {1,1,1,1};
    short s2 [] = {9,9,9};
    node * l1 = constructLink(s1,sizeof(s1)/sizeof(short));
    node * l2 = constructLink(s2,sizeof(s2)/sizeof(short));
    node * res = solution_add(l1,l2);
    printlink(res);
    return 0;
}
