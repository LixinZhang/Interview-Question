/*
 * Chapter 1.8
 * Question:Assume you have a method isSubstring which checks if one word is substring of 
 * another. Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using
 * only one call to isSubString(i.e."waterbottle" is a rotation of "erbottlewat")
 * 假设你有一个方法可以用来检测一个单词是否为一个另一个的子串。现在给你两个字符串并且只能进行一次substring的调用，判断s2是否为s1的转动形式。
 */

#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;


bool isSubstring(const char * s1, const char * s2){
    assert(s1 != NULL && s2 != NULL);
    return strstr(s1,s2) == NULL ? false : true;
}

/*
 * 首先应该检查s1与s2的长度，如果不想等，则直接判定为false
 * 对于字符串s1，s1s1则包含了s1转动后的所有形式，因此只要用isSubstring判断s2是否为s1s1的子串即可
 */

bool solution(const char * s1, const char * s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2) return false;
    char * temp = new char[len1*2];
    strcpy(temp,s1);
    strcpy(temp+len1,s1);
    bool res = isSubstring(temp,s2);
    delete [] temp;
    return res;
}
int main(){
    char s1 [] = "waterbottle";
    char s2 [] = "erbotdlewat";
    cout<<solution(s1,s2)<<endl;
}
