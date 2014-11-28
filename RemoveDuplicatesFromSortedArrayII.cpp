/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 28, 2014
    Problem:    Remove Duplicates from Sorted Array II
    Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

    Follow up for "Remove Duplicates":
    What if duplicates are allowed at most twice?

    For example,
    Given sorted array A = [1,1,1,2,2,3],

    Your function should return length = 5, and A is now [1,1,2,2,3].

    Solution:   Simpel simulation.
 */



class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2)    return n;

        int num = A[0];
        int count = 2;
        int offset = 0;
        for(int i=2; i<n; i++){
            if(i+offset < n)
                A[i] = A[i+offset];
            else
                break;
            
            if(A[i]!=A[i-1] || A[i]!=A[i-2])
                count++;
            else{
                offset++;
                i--;
            }
        }
        return count;

    }
};
