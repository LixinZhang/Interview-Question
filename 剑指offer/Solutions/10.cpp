#include<iostream>
using namespace std;

int one_cnt(int num){
    int ans = 0;
    while(num){
        num &= (num - 1);
        ans += 1;
    }
    return ans;
}

int main(){
    int cnt;
    cin>>cnt;
    int a;
    while(cnt > 0){
        cin >> a;
        cout<<one_cnt(a)<<endl;
        cnt --;
    }
   return 0;
}
