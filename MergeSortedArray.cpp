/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Merge Sorted Array
    Source:     https://oj.leetcode.com/problems/merge-sorted-array/

    Given two sorted integer arrays A and B, merge B into A as one sorted array.

    Note:
    You may assume that A has enough space (size that is greater or equal to m + n) 
    to hold additional elements from B. 
    The number of elements initialized in A and B are m and n respectively.

    Solution:   Adding from back to begin.
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        m--;n--;
        for(int i=m+n+1; i>=0; i--){
            if(m<0)             A[i] = B[n--];
            else if(n<0)        A[i] = A[m--];
            else if(A[m]<B[n])  A[i] = B[n--];
            else                A[i] = A[m--];
        }
    }
};
