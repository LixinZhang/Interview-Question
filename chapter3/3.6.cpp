/*
 * Write a program to sort a stack in ascending order. You should not make any assumptions about
 * how the stack is implemented.The following are the only functions that should be used to write
 * this program:push | pop | peek | isEmpty
 * 写程序实现對一个栈结构的排序。你不必假想这个栈是怎么实现的，你只允许使用栈的基本操作，比如push、pop、peek以及isEmpty
 */
#include<iostream>
#include<stack>
using namespace std;

/*
 * 我们假定题目中的升序是栈顶算起，即弹出的第一个元素应该最小。
 * 由于题目要求只允许使用栈的基本操作，于是，我们可以利用一个辅助栈b。
 * b存储的是有序的，从a中不断pop出元素item与b的top比较，如果改变了b的有序性，
 * 则将b中所有元素push到a中，然后将item push进b的栈底，最后再重复上诉过程。直到a为空为止。
 * 最后再将b中所有元素，push到a中，即完成了對a的排序。
 * 最坏的时间复杂度，为每次都会影响b的有序性，每次都会导致b中元素与a的交换，即为O（n*n）
 */

void stack_sort(stack<int> & a){
    stack<int> b;
    while(!a.empty()){
        int temp = a.top();
        a.pop();
        if (!b.empty() && b.top()>temp){
            while(!b.empty()){
                a.push(b.top());
                b.pop();
            }
        }
        b.push(temp);
    }
    while(!b.empty()) {
        a.push(b.top());
        b.pop();
    }
}
int main(){
    int arr [] = {2,1,3,0,8,1,6,9,7};
    stack<int> a;
    int length = sizeof(arr) / sizeof(int);
    for(int i=0;i<length;i++){
        a.push(arr[i]);
    }
    stack_sort(a);
    while(!a.empty()){
        cout<<a.top()<<endl;
        a.pop();
    }
    return 0;
}
