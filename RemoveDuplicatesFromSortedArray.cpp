/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 3, 2014
    Problem:    Remove Duplicates from Sorted Array 
    Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
    
    Note:       
    Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
    Do not allocate extra space for another array, you must do this in place with constant memory.

    For example,
    Given input array A = [1,1,2],
    Your function should return length = 2, and A is now [1,2].

    Solution:   Travel the array.
 */
                
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1)
            return n;
        
        int offset = 0;
        for(int i=1; i+offset<n ;i++){
            while(i+offset<n && A[i+offset]==A[i-1+offset])
                offset++;

            if(i+offset < n)
                A[i] = A[i+offset];
        }
        return n-offset;
    }
};
