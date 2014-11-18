/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 17, 2014
    Problem:    Search Insert Position
    Source:     https://oj.leetcode.com/problems/search-insert-position/
    Note:

    Given a sorted array and a target value, return the index if the target is found. 
    If not, return the index where it would be if it were inserted in order.

    You may assume no duplicates in the array.

    Here are few examples.
    [1,3,5,6], 5 → 2
    [1,3,5,6], 2 → 1
    [1,3,5,6], 7 → 4
    [1,3,5,6], 0 → 0

    Solution:   Binary Search
 */


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return binarySearch(A, 0, n-1, target);
    }
    
    int binarySearch(int *A, int start, int end, const int& target){
        int mid = (start+end) / 2;

        if(start > end)         return start;
        if(target == A[mid])    return mid;

        if(target < A[mid])
            return binarySearch(A, start, mid-1, target);
        else
            return binarySearch(A, mid+1, end, target);
    }
};
