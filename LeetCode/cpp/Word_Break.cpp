/*
 * Yahoo!的一道面试题，当时答得很糟糕，仔细分析下，还是很简单的。DP状态转移方程的建立是关键。
 * 定义sol[i]，表示从0到i是否可以满足约束，它可以拆分为子问题sol[i] = ( sol[k] and (str[k+1-i] in dict) )
 */

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution 
{
    public :
        bool wordBreak(string s, unordered_set<string> & dict)
        {
            bool * sol = new bool[s.size()];

            int len = s.size();

            for (int i=0; i < len; i++)
            {
                sol[i] = false;
                if (dict.find(s.substr(0, i + 1)) != dict.end())
                {
                    sol[i] = true;
                }
            }

            if (sol[len - 1]) return true;
            
            for (int i=1; i < len; i++)
            {
                for (int k=0; k<i; k++)
                {
                    if (sol[k] && (dict.find(s.substr(k + 1, i - k)) != dict.end())) 
                        sol[i] = true;
                }
                //cout<<i<<"\t"<<sol[i]<<endl;
            }

            delete []sol;
            if (sol[len - 1]) return true;
            return false;
        }
};


int main()
{
    string s = "bccdbacdbdacddabbaaaadababadad";

    string dictarr[] = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb", ""};
    unordered_set<string> dict;
    int idx = 0;
    while(true){
        if  (dictarr[idx] == "") break;
        dict.insert(dictarr[idx]);
        idx += 1;
    }

    Solution sol;
    bool res = sol.wordBreak(s, dict);

    cout<<res<<endl;
}

