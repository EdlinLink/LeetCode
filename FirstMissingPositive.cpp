/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 19, 2014
    Problem:    First Missing Positive 
    Source:     https://oj.leetcode.com/problems/first-missing-positive/
    Note:

    Given an unsorted integer array, find the first missing positive integer.

    For example,
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.

    Your algorithm should run in O(n) time and uses constant space.

    Solution:   1.  Pass-1 move the num to theirs proper position
                2.  Pass-2 incorrect position

 */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {

        if(n==0)    
            return 1;

        for(int i=0; i<n; i++){
            while(A[i]>=0 && A[i]<n && A[i]!=i ){
                if(A[A[i]]==A[i])
                    break;
                swap(A[A[i]], A[i]);
            }
        }

        int i = 1;
        for(; i<n; i++){
            if(i!=A[i])
                return i;
        }

        if(A[0] == i)
            return i+1;
        return i;
    }

    void swap(int &a, int&b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};
