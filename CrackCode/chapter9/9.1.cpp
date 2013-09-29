/*
 * You are given two sorted arrays, A and B, and A has a large enough buffer
 * at the end to hold B. Write a method to merge B into A sorted order.
 * 归并两个有序数组，问题的关键在于不需要重新开辟一个新的临时数组，从后往前添加到a中即可
 */
#include<iostream>
using namespace std;

void merge(int a[], int b[], int len1, int len2) {
    int backpos = len1 + len2 -1; 
    int i = len1-1;
    int j = len2-1;
    while(i>=0&&j>=0){
        if(a[i] > b[j]) {
            a[backpos--] = a[i--];
        }else{
            a[backpos--] = b[j--];
        }
    }
    while(i>=0){
        a[backpos--] = a[i--];
    }
    while(j>=0){
        a[backpos--] = b[j--];
    }
}

int main()
{
    int arr [100] = {1,3,6,88,556,3434,65656,454545};
    int arr2 [] = {1,2,3,4,5,6,7,34,234,234234,2342334};
    int size1 = 8;
    int size2 = 11;
    merge(arr,arr2,size1,size2);
    for(int i=0;i<size1+size2;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    return 0;
}
