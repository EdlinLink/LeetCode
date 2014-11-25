/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 25, 2014
    Problem:    Jump Game II 
    Source:     https://oj.leetcode.com/problems/jump-game-ii/
    Note:

    Given an array of non-negative integers, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Your goal is to reach the last index in the minimum number of jumps.

    For example:
    Given array A = [2,3,1,1,4]

    The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

    Solution:   0.  Jump one step from A[i] can reach range [A[i], A[i]+i]
                1.  Find max A[i]+i in range[i, A[i]+i]
                2.  Expand the reachable range
 */

class Solution {
public:

    int jump(int A[], int n) {
        int range = 0;
        int reach = 0;
        int jump = 0;

        while(range < n-1){
            range = reach + A[reach];
            findMax(A, reach);
            jump++;
        }
        return jump;
    }

    void findMax(int A[], int& reach){
        int max_index = reach;
        for(int i=reach; i<=reach+A[reach]; i++){
            if(A[i]+i > A[max_index]+max_index)
                max_index = i;
        }
        reach = max_index;
    }
};
