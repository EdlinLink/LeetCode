/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Add Binary 
    Source:     https://oj.leetcode.com/problems/add-binary/
    Note:

    Given two binary strings, return their sum (also a binary string).

    For example,
    a = "11"
    b = "1"
    Return "100".

    Solution:   1.  Make a and b the same length.
                2.  Add them together
                3.  Update the carry
 */ 

class Solution {
public:
    string addBinary(string a, string b) {

        string sum = "";
        int carry = 0;
        int index_a = a.size()-1;
        int index_b = b.size()-1;

        int x, y;

        while(index_a>=0 || index_b>=0){
            x = 0;
            y = 0;
            if(index_a >= 0){
                x = a[index_a]-'0';
                index_a--;
            }
            if(index_b >= 0){
                y = b[index_b]-'0';
                index_b--;
            }
            
            int c = carry+x+y;
            carry = c/2;
            c %= 2;
            sum = char('0'+c) + sum;
        }
        if(carry)
            sum = '1'+sum;

        return sum;
    }
};