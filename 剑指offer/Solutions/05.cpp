#include<iostream>
using namespace std;

struct node{
    int value;
    node * next;
    node(int v) {
        value = v;
        next = NULL;
    }
};

void reversePrintLink(node * head)
{
    if (head->next != NULL) reversePrintLink(head->next);
    cout<<head->value<<endl;
}

int main(){
    int num;
    cin>>num;
    node * head = new node(num);
    node * p = head;
    while(1){
        cin>>num;
        if(num < 0) break;
        p->next = new node(num);
        p = p->next;
    }
    reversePrintLink(head);
    return 0;
}
