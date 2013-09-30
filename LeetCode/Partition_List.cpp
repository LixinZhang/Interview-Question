/* http://oj.leetcode.com/problems/partition-list/
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */

/*
 */

#include<iostream>
#include<stdio.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


void printStatus(ListNode * head)
{  
   int limit = 10; 
    while(head)
    {
        limit -= 1;
        if (limit < 0 ) break;
        cout<<head->val<<'\t';
        head = head->next;
    }
    cout<<endl;
 
}



class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode * reshead = new ListNode(x-1);
            reshead->next = head;
            ListNode * tail = reshead;
            while(head != NULL && head->val < x) {
                head = head->next;
                tail = tail->next;
            }
            
            if (head==NULL){
                return reshead->next;
            }
            ListNode * p0 = head;
            ListNode * p1 = head->next;
            while(p1 != NULL) {
                if (p1->val < x) {
                   p0->next = p1->next;
                   tail->next = p1;
                   tail = p1;
                   p1 = p0->next;
                }else{
                    p0 = p0->next;
                    p1 = p1->next;
                }
            }
            tail->next = head;
            return reshead->next;
       }
};

int main() {
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(4);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(2);
    ListNode * node5 = new ListNode(5);
    ListNode * node6 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Solution s ;
    ListNode * head = s.partition(NULL, 3);
    
    while(head)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}
