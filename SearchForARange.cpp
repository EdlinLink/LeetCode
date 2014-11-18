/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 17, 2014
    Problem:    Search for a Range
    Source:     https://oj.leetcode.com/problems/search-for-a-range/
    Note:

    Given a sorted array of integers, find the starting and ending position of a given target value.
    Your algorithm's runtime complexity must be in the order of O(log n).
    If the target is not found in the array, return [-1, -1].

        For example,
        Given [5, 7, 7, 8, 8, 10] and target value 8,
        return [3, 4].

    Solution:   Binary Search
 */


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int pos = binarySearch(A, 0, n-1, target);

        vector<int> result;
        if(pos == -1){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int index = pos;
        while(index-1 >=0 && A[index-1]==target)
            index--;
        result.push_back(index);

        index = pos;
        while(index+1 <n && A[index+1]==target)
            index++;
        result.push_back(index);
       
        return result;
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
