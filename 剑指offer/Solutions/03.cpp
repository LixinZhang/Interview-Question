#include<iostream>
using namespace std;

int main()
{
    int m, n;
    int query = 0;
    int arr[1001][1001];
    while(cin>>m){
        cin>>n;
        cin>>query;
        for(int i=0 ;i<m; i++){
            for (int j=0; j<n; j++) cin>>arr[i][j];
        }
        int posi = 0;
        int posj = n-1;
        while(posi < m && posj>=0){
            if (arr[posi][posj] == query) {
                cout<<"Yes"<<endl;
                break;
            }
            else if(arr[posi][posj] > query) {
                posj--;
            }
            else{
                posi++;
            }
        }
        if (posi == m || posj < 0) cout<<"No"<<endl;
    }
    return 0;
}
