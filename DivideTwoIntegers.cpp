/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 3, 2014
    Problem:    Divide Two Integers
    Source:     https://oj.leetcode.com/problems/divide-two-integers/
    
    Note:       
    Divide two integers without using multiplication, division and mod operator.

    Solution:   Dividend - Divisor << shift
                result += (1 << shift);

                Pay attention to INT_MAX and INT_MIN.
                

 */
                

class Solution {
public:
    void abs(long long &x){
        if(x<0) x = -1*x;
    }

    int divide(int dividend, int divisor) {
        long long x = dividend;
        long long y = divisor;

        int sign = 1;
        if((x<0 || y<0) && !(x<0 && y<0) )
            sign = -1;

        abs(x);
        abs(y);
        long long result = 0;
        
        while(1){
            int shift = 0;
            long long tmp = y;

            while(x > tmp << 1){
                tmp <<= 1;
                shift++;
            }

            x -= tmp;
            if(x >= 0)
                result += (1 << shift);
            else
                break;
        }
    
        return sign*result;
    }
};
