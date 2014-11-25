/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 19, 2014
    Problem:    Trapping Rain Water
    Source:     https://oj.leetcode.com/problems/trapping-rain-water/
    Note:

    Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it is able to trap after raining.

    For example, 
    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

    Solution:   Find the largest num
                If there is only 1 largest num,
                    1.1 left-of-largest num decresing contain water
                    1.2 right-of-largest num increasing contain water
                If there is more than 1 largest num
                    2.1 left-of-first-largest num decresing contain water
                    2.2 right-of-last-largest num increasing contain water
                    2.3 between-first-last-largest contain water*distance

 */

class Solution {
public:
    int trap(int A[], int n) {
        if(0 == n)
            return 0;

        int first_largest = 0;
        int last_largest = n-1;
        for(int i=0; i<n; i++){
            if(A[i] >= A[last_largest]){
                last_largest = i;
                if(A[i] > A[first_largest])
                    first_largest = i;
            }
        }

        int total = 0;
        int current = A[0];
        for(int i=0; i<first_largest; i++){
            if(A[i] < current)
                total += (current - A[i]);
            else
                current = A[i];
        }

        int largest = A[first_largest];
        for(int i=first_largest; i<last_largest; i++){
            total += (largest - A[i]);
        }

        current = A[n-1];
        for(int i=n-1; i>last_largest; i--){
            if(A[i] < current)
                total += (current - A[i]);
            else
                current = A[i];
        }
        return total;
    }
};