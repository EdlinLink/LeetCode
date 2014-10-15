/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 15, 2014
    Problem:    Palindrome Number 
    Source:     https://oj.leetcode.com/problems/palindrome-number/
    Note:

    Determine whether an integer is a palindrome. Do this without extra space.

    Solution:   1. Filtering the integer to get the most left letter and the most right letter.
                2. Comparing the letter.

                Pay Attention:
                1. left_filter might overflow, set it to be "long long".
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)   return false;
        if(x < 10)  return true;

        long long left_filter = 10;
        int right_filter = 10;

        while(x/left_filter != 0)
            left_filter*=10;

        left_filter/=10;

        while(left_filter >= right_filter){
            if(x/left_filter != x%right_filter)
                return false;
            else{
                x %= left_filter;
                x /= right_filter;
                left_filter/=100;
            }
        }
        return true;
    }
};
