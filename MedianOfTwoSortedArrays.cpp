/*
    Author:		Edlin(LIN Junhao) edlinlink@qq.com
    Date:		Oct. 14, 2014
	Problem:	Median of Two Sorted Arrays
    Source:		https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
    Note:

    There are two sorted arrays A and B of size m and n respectively. 
    Find the median of the two sorted arrays. 
    The overall run time complexity should be O(log (m+n)).

    Solution:	Problem <=> Find the Kth element in A and B.
                1. Comparing the half K element in A and B
                2. If A[half] < B[half], A[0]~A[half] also small than Kth element. Drop them.
                3. Recursive doing step 2) until find the Kth element.
 */

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:

    bool Input_error = false;

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m+n;
        if(total%2 == 1)
            return findKth(A, m, B, n, total/2+1);
        else
            return ( findKth(A, m, B, n, total/2) + findKth(A, m, B, n, total/2+1) )/2; 
    }

    double findKth(int A[], int m, int B[], int n, int k){
        if(m > n)
            return findKth(B, n, A, m, k);
        if(m == 0)
            return B[k-1];
        if(k == 1)
            return min(A[0], B[0]);

        int pa = min(m, k/2);
        int pb = k - pa;

        if(A[pa-1] < B[pb-1])
            return findKth(A+pa, m-pa, B, n, k-pa);
        else if(A[pa-1] > B[pb-1])
            return findKth(A, m, B+pb, n-pb, k-pb);
        else
            return A[pa-1];
    }
};
