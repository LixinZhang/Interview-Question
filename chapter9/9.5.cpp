/*
 * Given a sorted array of strings which is interspersed with empty strings, write a method
 * to find the location of a given string.
 * Example: find "ball" in {"at","","","","ball","","","car","","","dad","",""}; return 4
 */

/*
 * 二分查找的变形
 * 遇到""，向一个方向找第一个非""的值，如果找不到，则在另一边进行子问题寻找
 */

#include<iostream>
#include<string>
using namespace std;


int binary_searchStr(string arr[], int length , string key){
    int low = 0;
    int high = length-1;
    while(low <= high) {
        int mid = (low+high) /2;
        if(arr[mid] == "") {
            while(mid <=high && arr[mid] == "") mid ++;
            if(mid > high){
                high = (low+high)/2 -1;
                continue;
            }
        }
        if (key == arr[mid]) return mid ;
        if(arr[mid] < key) low = mid+1;
        if(arr[mid] > key) high = (low+high)/2-1;
}
    return -1;
}


int main(){
    const int length = 13;
    string sorted_arr[length] = {"at","","","","ball","","","car","","","dad","",""};

    string a("at");
    string b("ball");
    string c("car");
    string d("dad");
    string e("hellworld");
    cout<<binary_searchStr(sorted_arr, length, a)<<endl; 
    cout<<binary_searchStr(sorted_arr, length, b)<<endl;; 
    cout<<binary_searchStr(sorted_arr, length, c)<<endl;
    cout<<binary_searchStr(sorted_arr, length, d)<<endl;
    cout<<binary_searchStr(sorted_arr, length, e)<<endl; 
    return 0;
}
