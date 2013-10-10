#include<iostream>
#include<assert.h>
#include<stdio.h>
using namespace std;

struct linknode{
    int val;
    linknode * next;
    linknode(int v) {
        val = v;
        next = NULL;
    }
};

linknode * solution(linknode * linkA, linknode * linkB){
    assert(linkA != NULL);
    assert(linkB != NULL);
    linknode * p1 = linkA;
    linknode * p2 = linkB;
    linknode * p0 = new linknode(0);
    linknode * reshead = p0;
    linknode * p3 = p0;
    while(p1 != NULL && p2 != NULL){
        int tmp_sum = p1->val + p2->val;
        p3->next = new linknode(tmp_sum % 10);
        p3 = p3->next;
        if (tmp_sum >= 10){
            p0->val += 1;
            while(p0->next != p3) {
                p0->next->val = 0;
                p0 = p0->next;
            }
        }else{
            if (tmp_sum < 9) p0 = p3;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    if (reshead->val != 0) return reshead;
    else return reshead->next;
}


int main(){
    //test
    linknode * a1 = new linknode(7);
    linknode * a2 = new linknode(7);
    linknode * a3 = new linknode(8);
    linknode * a4 = new linknode(2);
    linknode * a5 = new linknode(1);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    linknode * b1 = new linknode(2);
    linknode * b2 = new linknode(2);
    linknode * b3 = new linknode(2);
    linknode * b4 = new linknode(2);
    linknode * b5 = new linknode(2);
    b1->next = b2;
    b2->next = b3;
    b3->next = b4;
    b4->next = b5;
    
    linknode * res = solution(a1, b1);
    while(res != NULL){
        cout<<res->val<<"\t";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
