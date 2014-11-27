/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Climbing Stairs
    Source:     https://oj.leetcode.com/problems/climbing-stairs/
    Note:

    You are climbing a stair case. 
    It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps. 
    In how many distinct ways can you climb to the top?

    Solution:   1.  Total way at stair(n) = stair(n-1)+start(n-2)
                2.  stair(1) = 1, stair(2) = 1
                Trick:  start from 0.
 */ 


class Solution {
public:
    int climbStairs(int n) {
        n++;

        int a = 1;
        int b = 1;
        n-=2;
        while(n-- > 0){
            int c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};

