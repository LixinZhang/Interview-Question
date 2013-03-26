/*
 * Chapter 1.2
 * Question:Write code to reverse a c-Style String,
 * (C-style means that "abcd" is represented as five characters,including the null character)
 * 反转字符串
 */
#include<iostream>
#include<string.h>
using namespace std;

/*
 * 两种考虑，如果可以使用strlen函数，则可以省略找最后一个字符的工作
 * 否则，需要自己写
 */
void solution(char * str){
    int len = strlen(str);
    int i = 0;
    char temp;
    while(i < len/2){
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
        i++;
    }
}

void solution2(char * str) {
    char * end = str;
    char temp;
    while(*end != '\0'){
        end ++;
    }
    end --;
    while(str < end){
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main(){
    char s1[] = "hello world";
    char s2[] = "1234567890";
    solution(s1);
    solution2(s2);
    cout<<s1<<endl;
    cout<<s2<<endl;
    return 0;
}
