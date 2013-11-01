#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char s[1000000] ;
    cin.getline(s,1000000);
    int len = strlen(s);
    int space_cnt = 0;
    for(int i=0; i<len; i++) 
        if (s[i] == ' ') space_cnt += 1;
    int final_len = space_cnt * 2 + len;
    int idx = len;
    for (int j=final_len; j>=0; j--)
    {
        if (s[idx] == ' '){
            s[j] = '0';
            s[--j] = '2';
            s[--j] = '%';
        }else
            s[j] = s[idx];
        idx --;
    }
    cout<<s<<endl;
    return 0;
}
