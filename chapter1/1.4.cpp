/*
 * Chapter 1.4
 * Question: Write a method to decide if two strings are anagrams or not .
 * 判断两个字符串是否为易位够词，即排序之后相同的两个词
 * http://en.wikipedia.org/wiki/Anagram
 */

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

/*
 * 通过抽象定义,直接對两个string进行排序，然后判断下就可以了
 * 时间复杂度O(nlogn)
 */

bool solution(char * s1, char * s2){
    sort(s1,s1+strlen(s1));
    sort(s2,s2+strlen(s2));
    int cmp = strcmp(s1,s2);
    if( cmp == 0) return true;
    return false;
}

/*
 * 由于方法1具有数据侵入性，即改遍了s1和s2中原有的数据位置，因此不是很好的解决办法。
 * 利用空间换时间，用char_count统计s1中每个字符出现的次数
 * 然后遍历s2中的每个字符，對char_count进行更新，即对应的char_count减1
 * 如果某个字符对应的char_count减为-1,则判定为false
 * 若字符数不相等也判定为false
 */

bool solution2(char * s1, char * s2){
    int char_count[256] = {0};
    int len1=0,len2=0;
    while(*s1 != '\0') {
        char_count[*s1] ++;
        s1++;
        len1++;
    }
    while(*s2 != '\0') {
        char_count[*s2] --;
        if(char_count[*s2] < 0) return false;
        s2++;
        len2++;
    }
    if(len1 != len2) return false;
    return true;
}

int main(){
    char s1 [] = "hello";
    char s2 [] = "lloeh";
    cout<<solution(s1,s2);
    cout<<solution2(s1,s2);
    return 0;
}
