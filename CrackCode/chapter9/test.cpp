#include<iostream>
#include<string>
using namespace std;



int main(){
    const int length = 13;
    string sorted_arr[length] = {"at","","","","ball","","","car","","","dad","",""};

    string a("abc");
    string b("bcd");
    cout<< (a<b) <<endl;
    for(int i=0;i<length;i++){
        cout<<sorted_arr[i]<<endl;
    }
        
    return 0;
}
