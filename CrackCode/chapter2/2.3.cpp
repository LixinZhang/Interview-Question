/*
 * Chapter 2.3
 * Question:Implement an algorithm to delete a node in the middle of single linked list, given only access to that node.
 * Example
 * Input:the node 'c' from the linked list a->b->c->d->e
 * Output:nothing is returned, but the new linked list looks like a->b->d->e
 * 实现一个算法实现删除一个单链表中间的某个节点，只可以访问待删除的节点。
 * PS:是中间，而不能是最后一个节点。因为，如果要删除的是最后一个节点，那么它的pre节点的next需要设置为NULL，
 * 而只通过待删除节点是找不到它的pre节点的。
 */

#include<iostream>
using namespace std;

struct node {
    char c;
    node * next;
    node (char _c){
        c = _c;
        next = NULL;
    }
};

void printlink(node * head){
    while(head!=NULL){
        cout<<head->c<<"\t";
        head = head->next;
    }
    cout<<endl;
}

/*
 * 这是个已经出烂了的题了，O(1)操作删除指定节点，其原理就是把该节点的下一个节点完全复制过来
 * 其实最终删除的是该节点的下一个节点的内存地址
 */

void solution_deletenode(node * deletenode){
    node * p = deletenode->next;
    deletenode->c = deletenode->next->c;
    deletenode->next = deletenode->next->next;
    delete p;
}

int main()
{
    node * head = new node('a');
    node * b = new node('b');
    node * c = new node('c');
    node * d = new node('d');
    node * e = new node('e');
    head->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    printlink(head);
    solution_deletenode(c);
    printlink(head);
    return 0;
}
