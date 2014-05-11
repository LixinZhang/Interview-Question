#include<iostream>
using namespace std;

/*
 * 可以这么考虑，如果想把n从A移到C，则必须先把n-1移到B，然后再把B上的n-1移到C。
 * 步骤数量：2^N - 1
 */

void hanoi(int n, char A, char B, char C)
{
    if(n==1) {
        cout<<n<<" from "<<A<<" to "<<C<<endl;
        return ;
    }
    hanoi(n-1, A, C, B);
    cout<<n<<" from "<<A<<" to "<<C<<endl;
    hanoi(n-1, B, A, C);
}

int main(){
    hanoi(3, 'A', 'B', 'C');
    return 0;
}
