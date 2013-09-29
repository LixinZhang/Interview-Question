/*
 * Write a function to determine the number of bits required to convert integer A to
 * integer B.
 * Input: 31,14
 * Output: 2
 * 写一个函数判断两个整数A和B，相差多少bit，即转化A中多少个bit可以变为B。
 */
#include<iostream>
using namespace std;
/*
 * 按位异或，然后统计异或结果中的二进制表示1的个数
 */
int solution(int n, int m){
    int p  = n ^ m;
    int counter = 0;
    while(p>0){
        p = p & (p-1);
        counter++;
    }
    return counter;
}

int main(){
    cout<<solution((1<<30)-1,0)<<endl;
    return 0;
}
