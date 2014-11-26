/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Maximum Subarray 
    Source:     https://oj.leetcode.com/problems/maximum-subarray/
    Note:

    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
    the contiguous subarray [4,−1,2,1] has the largest sum = 6.

    Solution:   1.  Record the maximun sum of the current scan
                        If sum > 0, take it
                        Else sum <=0, ignore the previous num
                2.  Record the Maximun num in the array
                3.  If Maximun num < 0, Maximun num is the result
                    else the max_sum is the result. 
 */             

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0)
            return 0;

        int MAX = A[0];
        int max_sum = A[0];
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum < 0)
                sum = 0;
            if(A[i] > MAX)
                MAX = A[i];
            if(sum > max_sum)
                max_sum = sum;

        }
        return MAX>=0 ? max_sum : MAX;
    }
};
