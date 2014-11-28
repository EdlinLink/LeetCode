/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 28, 2014
    Problem:    Search in Rotated Sorted Array II
    Source:     https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/

    Follow up for "Search in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?

    Write a function to determine if a given target is in the array.

    Solution:   If dupicate is allowed, binarySearch will be no use.
                Scan once and find the target.
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        for(int i=0; i<n; i++)
            if(A[i] == target)
                return true;
        return false;
    }
    
};
