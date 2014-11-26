/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 25, 2014
    Problem:    Pow(x, n) 
    Source:     https://oj.leetcode.com/problems/powx-n/
    Note:

    Implement pow(x, n).
 */

class Solution {
public:
    double pow(double x, int n) {
        bool sign = true;

        if(n == 0)
            return 1;
        
        if(n < 0){
            sign = false;
            n *= -1;
        }

        double answer = 1;
        while(n>0){
            double result = x;
            double current_pow = 1;

            while(n >= current_pow*2){
                result *= result;
                current_pow *= 2;
            }

            n -= current_pow;
            answer *= result;
        }

        if(!sign)
            return 1/answer;
        return answer;
    }
};
