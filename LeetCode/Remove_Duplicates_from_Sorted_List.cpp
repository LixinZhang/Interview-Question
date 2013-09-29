/*
 * http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

/*
 * Solution:
 * 设置两个指针，分别指向item a，以及第一个与a不同的item b，然后将a的next指向b，即删除中间重复的a
 * 注意是否要delete，进行内存的释放
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
                    p1->next = p2;
                    p1 = p2;
                    p2 = p2->next;
                }else{
                    p1->next = NULL;
                    return pHead;
                }
            }
            return pHead;
       }
}
;

int main() {
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(1);
    ListNode * node3 = new ListNode(2);
    ListNode * node4 = new ListNode(2);
    ListNode * node5 = new ListNode(2);
    ListNode * node6 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Solution s ;
    ListNode * head = s.deleteDuplicates(node1);
    while(head)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}
