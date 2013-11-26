/*
 * http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
 */


/*
 * Solution:
 * 这道题是前一道题的衍生题目，这里利用给定节点p，不借助其他节点删除该节点的方法，即用p->next节点替换该节点，
 * 这里涉及到当最后所有点包含的情况下，无法在不提供pre节点而删除点p，所以重头又找了一遍
 * 这应该不是好的解决方案，以后再讨论
 */

#include<iostream>
#include<stdio.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (head == NULL) return head; 
            ListNode * pHead = head;
            ListNode * p1 = head; 
            ListNode * p2 = head->next;

            while(p2 != NULL) {
                while(p2 != NULL && p2->val == p1->val) {
                    p2 = p2->next;
                }
                if (p2 != NULL) {
                    if (p1->next != p2 ){
                        p1->val = p2->val;
                        p1->next = p2->next;
                        p2 = p2->next;
                    }else{
                        p1 = p2;
                        p2 = p1->next;        
                    }
                }else{
                    if (pHead->val == p1->val) return NULL;
                    ListNode * tmp = pHead;
                    while(tmp->next->val != p1->val) tmp = tmp->next;
                    tmp->next = NULL;
                    return pHead;
                }
            }
            if (p1 == p2) return NULL;
            return pHead;
       }
}
;

int main() {
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(1);
    /*
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(3);
    ListNode * node5 = new ListNode(3);
    ListNode * node6 = new ListNode(5);
    ListNode * node7 = new ListNode(5);
*/
    node1->next = node2;
  /*  
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
*/
    Solution s ;
    ListNode * head = s.deleteDuplicates(node1);
    while(head != NULL)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}
