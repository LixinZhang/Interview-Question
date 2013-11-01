#include<iostream>
using namespace std;

int sum(int a, int b)
{
    cout<<a<<"--"<<b<<endl;
    if (b == 0) return a;
    cout<<(a^b)<<"\t"<<((a&b)<<1)<<endl;
    return sum(a^b , ((a&b)<<1));
}

int main(){
    int a, b;
    while(cin>>a>>b)
        cout<<sum(a,b)<<endl;
    return 0;
}
