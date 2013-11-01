#include<iostream>
using namespace std;

void solution_01(){
    int f[71];
    f[1] = 1;
    f[2] = 2;
    int n;
    for(int i=3; i<=70; i++) {
        f[i] = f[i-1] + f[i-2];
    }
     while(cin >> n)
         cout<<f[n]<<endl;
}

int main(){
    solution_01();
    return 0;
}
