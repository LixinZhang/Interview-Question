#include<iostream>
using namespace std;

int _strlen(const char * s){
    const char * p = s;
    while((*p) != '\0') p++;
    return (p - s);
}

int main(){
    char str[] = "Helloworld";
    cout<<_strlen(str)<<endl;
    return 0;
}
