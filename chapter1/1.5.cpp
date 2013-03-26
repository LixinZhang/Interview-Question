/*
 * Chapter 1.5
 * Question:Write a method to replace all spaces in a string with '%20'
 * 写一个方法用'%20'替换字符串中的所有空格
 */
#include<iostream>
#include<string.h>
using namespace std;

/*
 * 这应该算是比较典型的字符串移位的问题
 * 首先，如果我们知道了字符串中包含的space数量count，那么替换后的最终长度比原始长度增加了count*2
 * 在进行替换过程中，如果从头开始替换，势必在替换过程中，需要對后面的字符进行位置移动，显然这是开销很大的。
 * 由于我们已经知道了替换后的最终长度，那么便可以从后往前进行替换，这样不会對前面的字符产生影响。
 * 另外，由于字符串的最终长度增加了，那么在原有内存上进行操作，可能会造成字符串的访问越界。
 * 因此，最好的方法应该时新建一个string，再返回，这样的话，就无所谓替换的顺序了。
 */

void solution(char * str){
    //我们假设str申请的空间很大，不会产生越界问题
    int count = 0;
    int len = 0;
    char * pstr = str;
    while(*pstr != '\0'){
        if (*pstr == ' ') count++;
        len ++;
        pstr++;
    }
    int final_len = len + 2 * count;
    str[final_len] = '\0';
    int pos = final_len - 1;
    int j = len - 1;
    while(j>=0){
        if(str[j] != ' ') str[pos--] = str[j];
        else{
            str[pos - 2] = '%';
            str[pos - 1] = '2';
            str[pos] = '0';
            pos -=3;
        }
        j--;
    }
}

int main(){
    char str [100];
    strcpy(str," hello world python ");
    solution(str);
    cout<<str<<endl;
    return 0;
}
