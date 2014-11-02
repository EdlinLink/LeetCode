/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 2, 2014
    Problem:    Generate Parentheses
    Source:     https://oj.leetcode.com/problems/generate-parentheses/
    
    Note:       
    Given n pairs of parentheses, 
    write a function to generate all combinations of well-formed parentheses.

    For example, given n = 3, a solution set is:
    "((()))", "(()())", "(())()", "()(())", "()()()"

    Solution:   Recursively make the bracket.                        
 */


class Solution {
public:

    vector<string> result;
    vector<string> generateParenthesis(int n) {
        result.clear();
        addbracket("", n, 0);
        return result;
    }
    
    void addbracket(string s, int n, int m){
        if(n==0 && m==0){
            result.push_back(s);
            return ;
        }

        if(n>0) addbracket(s+'(', n-1, m+1);
        if(m>0) addbracket(s+')', n, m-1);
    }

};
