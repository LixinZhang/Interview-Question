#include<iostream>
using namespace std;


int inorder(int * arr, int low , int high){
    int ans = arr[low];
    for (int i=low+1; i<=high; i++){
        if (ans > arr[i]) {ans = arr[i];break;}
    }
    return ans;
}

int findMin(int arr[], int len){
    int low = 0; int high = len - 1;
    if (arr[low] < arr[high]) return arr[low];
    while(low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == arr[low] && arr[mid] == arr[high]) return inorder(arr, low, high);
        if (arr[mid] <= arr[high])
        {
            high = mid;
        }
        else if(arr[mid] >= arr[high]){
            low = mid;
        }
        if (low + 1 == high) break;
    }
    return arr[high];
}

int main(){
    int arr[1000001];
    int n;
    while(cin >> n){
        for(int i=0; i<n; i++) cin >> arr[i];
        cout<<findMin(arr, n)<<endl;
    }
    return 0;
}
