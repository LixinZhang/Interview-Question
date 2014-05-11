#MaxDistanceMonotonic
##Task Description

    :::desc
    A non-empty zero-indexed array A consisting of N integers is given.
    A monotonic pair is a pair of integers (P, Q), such that 0 ≤ P ≤ Q < N and A[P] ≤ A[Q].
    The goal is to find the monotonic pair whose indices are the furthest apart. More precisely, we should maximize the value Q − P. It is sufficient to find only the distance.
    For example, consider array A such that:
        A[0] = 5
        A[1] = 3
        A[2] = 6
        A[3] = 3
        A[4] = 4
        A[5] = 2
    There are eleven monotonic pairs: (0,0), (0, 2), (1, 1), (1, 2), (1, 3), (1, 4), (2, 2), (3, 3), (3, 4), (4, 4), (5, 5). The biggest distance is 3, in the pair (1, 4).
    Write a function:
    int solution(vector<int> &A);
    that, given a non-empty zero-indexed array A of N integers, returns the biggest distance within any of the monotonic pairs.
    For example, given:
        A[0] = 5
        A[1] = 3
        A[2] = 6
        A[3] = 3
        A[4] = 4
        A[5] = 2
    the function should return 3, as explained above.
    Assume that:
    N is an integer within the range [1..300,000];
    each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
    Complexity:
    expected worst-case time complexity is O(N);
    expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
    Elements of input arrays can be modified.



##Analysis
一开始，想不到O(n)的解法，考虑过用辅助数组从头和尾遍历求最大或最小值来帮助问题解决。但是后来仍然没想出来。后来，看了答案之后，才恍然大悟，这里好好记录下。

用low[i]记录从0到i的最小值，用high[i]记录从n-1到i的最大值。
于是low[i]与high[i]均是递增序列。
    

##Solution
    :::cpp
    // you can also use includes, for example:
    // #include <algorithm>
    int solution(vector<int> &A) {
        // write your code in C++98
        int len = A.size();
        if (len==0) return 0;
        int * low = new int[len];
        int * high = new int[len];
        int res = 0;
        low[0] = A[0];
        for(int i=1; i<len; i++){
            low[i] = min(A[i], low[i-1]);
        }
        high[len-1] = A[len-1];
        for(int i=len-2; i>=0; i--){
            high[i] = max(A[i], high[i+1]);
        }
        //like merge sort
        int i=0;
        int j=0;
        while(i< len && j< len){
            if (low[i] <= high[j]){
                res = max(res, j-i);
                j++;
            }else{
                i++;
            }
        }
        return res;
    }