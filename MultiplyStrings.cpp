/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 19, 2014
    Problem:    Multiply Strings
    Source:     https://oj.leetcode.com/problems/multiply-strings/
    Note:

    Given two numbers represented as strings, return multiplication of the numbers as a string.
    Note: The numbers can be arbitrarily large and are non-negative.

    Solution:   Big Integer Mutiplication

 */

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len = len1+len2;
        int *digit = new int[len];

        for(int i=0; i<len; i++)
            digit[i] = 0;

        int carry = 0;
        for(int i=len1-1; i>=0; i--){
            for(int j=len2-1; j>=0; j--){
                digit[i+j+1] += carry + (num1[i]-'0') * (num2[j]-'0');
                digit[i+j] += digit[i+j+1] / 10;
                digit[i+j+1] %= 10;
            }
        }

        string result = "";
        for(int i=0; i<len; i++){
            if(digit[i]!=0){
                while(i<len)
                    result += char('0'+digit[i++]);
            }
        }

        delete []digit;
        return "" == result ? "0" : result;
    }
};
