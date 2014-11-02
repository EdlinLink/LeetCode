/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 2, 2014
    Problem:    Valid Parentheses
    Source:     https://oj.leetcode.com/problems/valid-parentheses/ 
    
    Note:       
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
    determine if the input string is valid.

    The brackets must close in the correct order, 
    "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

    Solution:   Use stack
 */

#include <stack>
using namespace std;

class Solution {
public:
    stack<char> sta;

    bool isValid(string s) {
        while(!sta.empty())
            sta.pop();

        for(int i=0; i<s.size(); i++){
            if(!sta.empty()){
                switch(s[i]){
                    case ')':
                        if(sta.top()=='(')
                            sta.pop();
                        break;
                    case '}':
                        if(sta.top()=='{')
                            sta.pop();
                        break;
                    case ']':
                        if(sta.top()=='[')
                            sta.pop();
                        break;
                    default:
                        sta.push(s[i]);
                }
            }
            else
                sta.push(s[i]);
        }
        return sta.empty();
    }
};