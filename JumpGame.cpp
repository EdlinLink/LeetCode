/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Jump Game
    Source:     https://oj.leetcode.com/problems/jump-game/
    Note:

    Given an array of non-negative integers, 
    you are initially positioned at the first index of the array.
    
    Each element in the array represents your maximum jump length at that position.
    Determine if you are able to reach the last index.

    For example:
    A = [2,3,1,1,4], return true.
    A = [3,2,1,0,4], return false.

    Solution:   Update he maximun reachable range.

 */ 

class Solution {
public:
    bool canJump(int A[], int n) {
        int reach_range = 0;
        for(int i=0; i<=reach_range; i++){
            if(reach_range >= n-1)
                return true;

            if(A[i]+i > reach_range)
                reach_range = A[i]+i;
        }
        return false;
    }
};
