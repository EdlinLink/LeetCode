/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Plus One
    Source:     https://oj.leetcode.com/problems/plus-one/
    Note:

    Given a non-negative number represented as an array of digits, plus one to the number.
    The digits are stored such that the most significant digit is at the head of the list.

    Solution:   1.  Add one to the last element.
                2.  Scan from the last to the first.
 */ 

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for(int i=digits.size()-1; i>=0; i--){
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i]%=10;
        }
        if(carry)
            digits.insert(digits.begin(), carry);

        return digits;
    }
};
