/*
 * Given a (decimal -eg 3.72) number that is passed as a string, print the binary representation.
 * If the number can not be represented accurately in binary, print 'Error'
 * 打印一个字符串表示的浮点型整数的二进制表示形式。
 * PS：这个得了解double型数据的表示形式，这个之前对细节还真不知道。
 */
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void print_format(char * s){
    for(int i=0;i<64;i++) {
        cout<<s[i];
        if(i== 0|| i == 11) cout<<"\t";
    }
    cout<<endl;
}

void parse_integer(int num, char * binaryPresentation, int & position , int reverse_end = -1){
    int start = position;
    while(num > 0){
        if (num % 2 == 0) {
            binaryPresentation[position++] = '0';
        }else{
            binaryPresentation[position++] = '1';    
        }
        num /= 2;
     }
    int end = position - 1;
    if (reverse_end != -1 ) end = reverse_end;
    while(start <= end){
        swap(binaryPresentation[start++], binaryPresentation[end--]);
    }
}

void parse_decimal (double flag, char * binaryPresentation, int & position, int count) {
    double temp = 0.5;
    double ans = 0.0;
    while(count > 0){
        if (temp + ans < flag) {
            binaryPresentation[position++] = '1';
            ans += temp;
            temp *= 0.5;
        }else{
            binaryPresentation[position++] = '0';
            temp *= 0.5;
        }
        count --;
    }
}

char * solution(char * str){
    char * binaryPresentation = new char [64];
    for(int i=0;i<64;i++) binaryPresentation[i] = '0';
    int len = strlen(str);
    if (str[0] == '-') binaryPresentation[0] = '1';
    else binaryPresentation[0] = '0';
    int dot = 0;
    for(int i=0;i<len;i++) {
        if(str[i] == '.') dot = i;
    }
    double decimal = atof(str+dot);
    str[dot] = '\0';    
    double integer_part = atoi(str);
    int position = 11;
    int start = position;
    parse_integer(integer_part, binaryPresentation, position);
    binaryPresentation[11] = '0';
    int exponent = position - start - 1;
    parse_decimal(decimal, binaryPresentation, position, 53-exponent-2);
    position = 1;
    parse_integer(exponent + 1023, binaryPresentation, position, 11);
    return binaryPresentation;
}


int main(){
    //test cases
    char s2[] = "38414.4";
    char s[] = "20.59375";
    char s3[] = "123.";
    char * representation = solution(s2);
    print_format(representation);
    delete representation;
    return 0;
}
