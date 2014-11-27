/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Sqrt(x) 
    Source:     https://oj.leetcode.com/problems/sqrtx/
    Note:

    Implement int sqrt(int x).
    Compute and return the square root of x.

    Solution:   NewTon Iteration
 */ 


class Solution {
public:
    int sqrt(int x) {
        if(x==0)
            return 0;
        
        double old_result;
        double result = x;
        do{
            old_result = result;
            result = (result + x/result)/2;
        }while(old_result - result > 0.0000001);

        return result;
    }
};

