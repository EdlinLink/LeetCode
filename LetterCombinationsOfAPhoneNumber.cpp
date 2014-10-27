/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 27, 2014
    Problem:    Letter Combinations of a Phone Number
    Source:     https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
    Note:

    Given a digit string, return all possible letter combinations that the number could represent.
    A mapping of digit to letters (just like on the telephone buttons) is given below.

    1:      2: abc  3: def
    4: ghi  5: jkl  6: mno
    7: pqrs 8: tuv  9: wxyz

    Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

    Note:
    Although the above answer is in lexicographical order, your answer could be in any order you want.

    Solution:   Backtracking, DFS

    Reference:  https://oj.leetcode.com/discuss/1083/use-deep-first-search-dfs-idea-is-there-any-better-solutions
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    vector<string> Letter(string *num, string digits){
        vector<string> v;

        if(digits.size()==0){
            v.push_back("");
        }
        else{
            vector<string> remain = Letter(num, digits.substr(1));
            string c = num[digits[0]-'0'];
            for(int i=0; i<c.size(); i++){
                for(int j=0; j<remain.size(); j++){
                    v.push_back(c[i]+remain[j]);
                }
            }
        }

        return v;
    }

    vector<string> letterCombinations(string digits) {
        string num[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result = Letter(num, digits);
        return result;
    }    
};
