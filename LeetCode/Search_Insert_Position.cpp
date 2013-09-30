/*http://oj.leetcode.com/problems/search-insert-position/
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */
#include<iostream>
using namespace std;

class Solution {
public :
    int searchInsert(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        while( low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] > target){
                if (mid == 0) return 0;
                if (mid > 0 && A[mid-1] < target) return mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};


int main(){
    Solution s;
    int arr[] = {1,3,5,6};
    cout << s.searchInsert(arr, 4, 5) << endl;
    cout << s.searchInsert(arr, 4, 2) << endl;
    cout << s.searchInsert(arr, 4, 7) << endl;
    cout << s.searchInsert(arr, 4, 0) << endl;
    return 0;
}
    
