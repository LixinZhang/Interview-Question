#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public :
        void reorderList(ListNode * head) 
        {
            if (head == NULL) return;
            ListNode * p1 = head;
            ListNode * head_next = p1->next;
            if (head_next == NULL) return;
            ListNode * p2 = head->next;
            while(p1 != NULL && p1->next != NULL && p2!=NULL && p2->next != NULL) 
            {
                p1->next = p1->next->next;
                p1 = p1->next;
                p2->next = p2->next->next;
                p2 = p2->next;
            }
            if (p1 != NULL && p1->next != NULL) p1->next = NULL;
            if (p2 != NULL && p2->next != NULL) p2->next = NULL;
           
            p1 = head;
            p2 = head_next;
            
            //reverse link
            ListNode * pre, * next;
            pre = p2;
            p2 = p2->next;
            pre->next = NULL;
            while(p2 != NULL) 
            {
                next = p2->next;
                p2->next = pre;
                pre = p2;
                p2 = next;
            }
            p2 = pre;

            //merge the two link
            ListNode * res = p1;
            while(p1 != NULL && p2 != NULL) 
            {
                next = p1->next;
                p1->next = p2;
                p2 = p2->next;
                p1->next->next = next;
                p1 = next;
            }
            while(res != NULL) 
            {
                cout<<res->val<<"\t";
                res = res->next;
            }
            cout<<endl;
        }

        void reorderList2(ListNode * head) 
        {
            if (head == NULL|| head->next == NULL) return;
            ListNode * p1, * p2;
            p1 = head;
            p2 = p1;
            while(p2 != NULL && p2->next != NULL)
            {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            //reverse link
            p2 = p1;
            ListNode * pre, * next;
            pre = p2;
            p2 = p2->next;
            pre->next = NULL;
            while(p2 != NULL) 
            {
                next = p2->next;
                p2->next = pre;
                pre = p2;
                p2 = next;
            }
            p2 = pre;
            
            

            //merge the two link
            p1 = head;
            ListNode * res = p1;
            while(p1 != NULL && p2 != NULL) 
            {
                next = p1->next;
                p1->next = p2;
                p2 = p2->next;
                p1->next->next = next;
                p1 = next;
            }
            if (p1 != NULL && p1->next != NULL) p1 ->next = NULL;
            while(res != NULL) 
            {
                cout<<res->val<<"\t";
                res = res->next;
            }
            cout<<endl;
 
        }
};

int main()
{
    ListNode * head = new ListNode(1);
    ListNode * p1 = head;
    int arr[] = {2,3,4,5,6,7,8};
    //int arr[] = {};
    int size = sizeof(arr) / sizeof(int);
    for( int i=0; i < size; i++)
    {
        p1->next = new ListNode(arr[i]);
        p1 = p1->next;
    }
    Solution s;
    s.reorderList2(head);
    return 0;
}
