#include<iostream>
using namespace std;

int _atoi(const char * s){
    if (s == NULL || s == '\0') return 0;
    int start = 0;
    while(s[start]!='\0' && s[start]==' ') start++;
    if (s[start] == '\0') return 0;
    bool negative = false;
    if (s[start] == '-' ) {negative = true; start++;}
    if (s[start] == '+' ) {start++;}
    int result = 0;
    int p = start;
    while(s[p] != '\0'){
        if (s[p] < '0' || s[p] > '9') return negative ? result * (-1) : result;;
        int bound = INT_MAX - (s[p] - '0') ;
        if (result > bound/10) return negative ? INT_MIN : INT_MAX ;
        result = result * 10 + s[p] - '0';
        p++;
    }
    return negative ? result * (-1) : result;
}

int main(){
    char s [] = "123";
    char s2 [] = "  -1233433434124";
    char s3 [] = "-123124";
    cout<<_atoi(s)<<endl;
    cout<<_atoi(s2)<<endl;
    cout<<_atoi(s3)<<endl;
    cout<<(1<<31) & (-123)<<endl;
    return 0;
}
