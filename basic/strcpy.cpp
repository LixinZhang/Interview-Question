#include<iostream>
using namespace std;

char * _strcpy(char * dest , const char * from){
    char * to = dest;
    if(to == NULL || from == NULL) return NULL;
    while( (*(to++) = *(from++)) != '\0') {}
    return dest;
}

int main(){
    char to[128];
    char from[] = "helloworld";
    char * dest = _strcpy(to, from);
    cout<<dest<<endl;
    return 0;
}
