#include<iostream>
using namespace std;
/*
 * nlogn算法，算法细节详情见《编程之美》 2.16  
 */
int binarySearch(int * arr, int low, int high, int key){
    if (low > high || (low == 1 && high == 1 && arr[low] > key)) return -1;
    int mid = (low+high) / 2;
    if(arr[mid] == key || low == high) return mid;
    else if (arr[mid] < key) {
        if (mid + 1 <= high && arr[mid+1] > key) return mid + 1;
        else return binarySearch(arr,mid+1,high,key);
    }
    else{
        return binarySearch(arr,low,mid-1,key);
    }
}

int LIS(int * arr, const int length){
    int maxlen = 1;
    int maxV[length];
    int lis[length];
    maxV[1] = arr[0];
    lis[0] = 1;
    for(int i=1;i<length;i++){
        int pos = binarySearch(maxV,1,maxlen,arr[i]);
        if (pos < 0) {
            lis[i] = 1;
            maxV[1] = arr[i];
        }
        else {
            lis[i] = pos + 1;
            if (lis[i] > maxlen) {
                maxlen++;
                maxV[maxlen] = arr[i];
            }
            else if(maxV[pos+1] > arr[i] && maxV[pos] < arr[i] )
             maxV[pos+1] = arr[i];
        }
    }
    return maxlen;
}

int LIS2(int * arr, const int length){
    int f[length];
    int ans = 1;
    f[0] = 1;
    for(int i=1;i<length;i++){
        f[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[i] >= arr[j] && f[i] < f[j] + 1 ) f[i] = f[j] +1;
        }
        if(ans<f[i]) ans = f[i];
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int arr2[] = {9,8,7,6,5,4,3,2,1};
    int arr3[] = {1,-1,2,-3,4,-5,6,-7};
    int length = sizeof(arr) / sizeof(int);
    cout<<LIS(arr3,length)<<endl;
    cout<<LIS2(arr3,length)<<endl;
    return 0;
}
