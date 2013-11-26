#include<iostream>
using namespace std;

/*
 *
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = strlen(s);
        int pre = 0;
        int post = length - 1;
        while(pre < length && s[pre] == ' ') pre ++;
        while(post > 0 && s[post] == ' ') post --;
        if(pre >post) return 0;
        int idx = post; 
        while(idx >= pre && s[idx] != ' ') idx --;
        if (idx < pre) return post - pre + 1;
        else return post - idx;
    }
};

int main()
{
    Solution s ;
    cout<<s.lengthOfLastWord(" Today is a nice day")<<endl;
    cout<<s.lengthOfLastWord(" Today is a nice day  ")<<endl;
    cout<<s.lengthOfLastWord(" Today is a nice   day")<<endl;
    cout<<s.lengthOfLastWord("  day")<<endl;
    cout<<s.lengthOfLastWord("day   ")<<endl;
    cout<<s.lengthOfLastWord("  day   ")<<endl;
    cout<<s.lengthOfLastWord("   ")<<endl;
    cout<<s.lengthOfLastWord("")<<endl;
    cout<<s.lengthOfLastWord("a")<<endl;

    return 0;
}
