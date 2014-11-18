/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 17, 2014
    Problem:    Search in Rotated Sorted Array 
    Source:     https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
    Note:

    Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    You are given a target value to search. If found in the array return its index, otherwise return -1.
    You may assume no duplicate exists in the array.

    Solution:   Cut the array into two parts:   [start, mid], [mid+1, end]
                1.  If (A[start]<=A[mid]), [start,mid] no flip. 
                    If target is in [start, mid], find it in binary search. 
                2.  If (A[start]>A[mid]), there is a flip. 
                    If (target<=A[mid] && target>=[start], find it in binary search.
                Same as [mid+1, end].
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        return realSearch(A, 0, n-1, target);
    }
    
    int realSearch(int *A, int start, int end, const int& target){
        int mid = (start+end) / 2;

        if(start > end)     return -1;
        if(target == A[mid])   return mid;

        if(A[start] <= A[mid]){
            if(A[start] <= target && target < A[mid])
                return binarySearch(A, start, mid-1, target);
            else
                return realSearch(A, mid+1, end, target);
        }
        else{
            if(A[start] <= target || target < A[mid])
                return realSearch(A, start, mid-1, target);
            else
                return binarySearch(A, mid+1, end, target);
        }
    }

    int binarySearch(int *A, int start, int end, const int& target){
        int mid = (start+end) / 2;

        if(start > end)     return -1;
        if(target == A[mid])   return mid;

        if(target < A[mid])
            return binarySearch(A, start, mid-1, target);
        else
            return binarySearch(A, mid+1, end, target);
    }
};