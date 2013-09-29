/*
 * Chapter 3.5
 * Question:Implement a MyQueue class which implements a queue using two stacks.
 * 使用两个栈实现一个队列
 */

#include<iostream>
#include<stack>
using namespace std;

/*
 * 这个是很经典的问题了，不做解释了。
 */
class MyQueue{
    public :
        void push(int e) {
            a.push(e);
        }
        int front(){
            if(b.empty()){
                while(!a.empty()){
                    b.push(a.top());
                    a.pop();
                }
            }
            return b.top();
        }
        void pop(){
            if (b.empty()){
                while(!a.empty()){
                    b.push(a.top());
                    a.pop();
                }
            }
            b.pop();
        }
        bool empty(){
            return (a.empty() && b.empty());
        }
    private :
        stack<int> a,b;
};
int main(){
    int arr[] = {2,1,3,0,8,1,6,9,7};
    int length = sizeof(arr) / sizeof(int);
    MyQueue q;
    for(int i=0;i<length;i++){
        q.push(arr[i]);
    }
    cout<<q.front()<<endl;
    q.pop();
    for(int i=0;i<length;i++){
        q.push(arr[i]);
    }
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}
