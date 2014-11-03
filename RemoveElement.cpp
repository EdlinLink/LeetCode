/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 3, 2014
    Problem:    Remove Element
    Source:     https://oj.leetcode.com/problems/remove-element/
    
    Note:       
    
    Given an array and a value, remove all instances of that value in place and return the new length.
    The order of elements can be changed. It doesn't matter what you leave beyond the new length.

    Solution:   Remove element in array.
                Move the rest elements one step ahead.
 */
                
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int offset = 0;
        for(int i=0; i+offset<n; i++){
            while(i+offset< n && A[i+offset] == elem){
                offset++;
            }
            if(i+offset<n)
                A[i] = A[i+offset];
        }
        return n-offset;
    }
};
