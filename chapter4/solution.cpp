#include<iostream>
using namespace std;

int flag [100][100][200] = {0};

bool check(string & s1, string & s2, string & s3, int p1, int p2, int p3)  {
    //cout<<p1<<"\t"<<p2<<"\t"<<p3<<endl;
    if (flag[p1][p2][p3] != 0) {
        if (flag[p1][p2][p3] == 1) return true;
        else return false;
    }
    if (p1 == s1.size()  && p2 == s2.size() ) return true;
    if (p1 == s1.size()) {
        while(p2 < s2.size() && s2[p2] == s3[p3]){
            p2++;
            p3++;
        }
        if (p2 == s2.size()) return true;
        else return false;
    }
    if (p2 == s2.size()) {
        while(p1 < s1.size() && s1[p1] == s3[p3]) {
            p1 ++;
            p3 ++;
        }
        if (p1 == s1.size()) return true;
        else return false;
    }
    flag[p1][p2][p3] = 1;
    if (s1[p1] == s3[p3] && s2[p2] != s3[p3]) return check(s1,s2,s3,p1+1,p2,p3+1);
    if (s1[p1] != s3[p3] && s2[p2] == s3[p3]) return check(s1,s2,s3,p1,p2+1,p3+1);
    if (s1[p1] == s3[p3] && s2[p2] == s3[p3]) return ( check(s1,s2,s3,p1+1,p2,p3+1) || check(s1,s2,s3,p1,p2+1,p3+1) );
    flag[p1][p2][p3] = 2;
    if (s1[p1] != s3[p3] && s2[p2] != s3[p3]) return false;
}

bool isInterleave(string s1, string s2, string s3) {
    if(s1.size() + s2.size() != s3.size() ) return false;
    return check(s1,s2,s3,0,0,0);
}


int main() {
    string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    //string s3 = "aadbbcbcac";
    string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    cout<<isInterleave(s1,s2,s3)<<endl;
    return 0;
}
