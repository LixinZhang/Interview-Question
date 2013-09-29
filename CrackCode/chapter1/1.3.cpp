/*
 * Chapter 1.3
 * Question:Design an algorithm and write code to remove the duplication characters in a string
 * without using any addtional buffer. NOTE:One or two addtional variables are fine.
 * An extra copy of the array is not.
 * FOLLOW UP
 * Write the test cases for this method.
 * 设计一个算法，用来移除一个字符串中重复的字符，并且不允许使用任何额外的空间（少量变量可以）
 * 不允许额外的拷贝
 * 接下来，为这个方法写一些测试用例
 */
#include<iostream>
#include<string.h>

using namespace std;
/*
 * 由于不允许使用额外空间，导致不能用1.1中类似的方法判断是否重复
 * 因此，采用遍历枚举的方式，方法如下：
 * 对于str[i]，枚举0～tail之间是否已存在该元素，其中0到tail之间字符不重复
 * 如果存在，则跳过，否则str[tail]更新为新元素str[i]
 */
void solution(char * str){
    if (str == NULL) return ;
    int len = strlen(str);
    int tail = 1;
    int j;
    for(int i=1;i<len;i++){
        for(j=0;j<tail;j++){
            if (str[i] == str[j]) break;
        }
        if(j == tail) {
            str[tail] = str[i];
            tail++;
        }
    }
    str[tail] = '\0';
}

/*
 * Test Cases:
 * 1. 不包含任何重复字符 abcd
 * 2. 所有的字符均重复 aaaa
 * 3. NULL
 * 4. 连续重复的字符串，如aaabbb
 * 5. 非连续重复的字符串 abcabcddeef
 */

int main(){
    char s [] = "abcdeagsdgabc";
    solution(s);
    cout<<s<<endl;
    return 0;
}
