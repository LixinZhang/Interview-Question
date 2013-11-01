#include<iostream>
#include<stack>
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
    stack<node *> sta;
    while(head != NULL){
        sta.push(head);
        head = head->next;
    }
    while(!sta.empty()){
        cout<<sta.top()->value<<endl;
        sta.pop();
    }
}

int main(){
    int num;
    stack<int> sta;
    while(1){
        cin>>num;
        if(num < 0) break;
        sta.push(num);    
    }
    while(!sta.empty()){
        cout<<sta.top()<<endl;
        sta.pop();
    }
    return 0;
}
