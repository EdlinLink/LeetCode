/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 15, 2014
    Problem:    Reverse Integer 
    Source:     https://oj.leetcode.com/problems/reverse-integer/
    Note:

    Reverse digits of an integer.

    Example1: x = 123, return 321
    Example2: x = -123, return -321

    Solution:   Simulation directly
                1. Pay attention to "xyz" that "zyx" is beyond integer.
 */

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
            sign = -1;
            x*=(-1);
        }

        long reverse_num = 0;
        while(x!=0){
            reverse_num = reverse_num*10 + x%10;
            x/=10;
        }

        reverse_num = sign * reverse_num;
        assert(INT_MIN < reverse_num && reverse_num < INT_MAX);
        return reverse_num;
    }
};
