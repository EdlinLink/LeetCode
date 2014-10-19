/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 19, 2014
    Problem:    Longest Common Prefix 
    Source:     https://oj.leetcode.com/problems/longest-common-prefix/
    Note:

    Write a function to find the longest common prefix string amongst an array of strings.

    Solution:   1. Sort the string
                2. Using the shortest one to comparing to other string
 */

#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())
            return "";

        sort(strs.begin(), strs.end());
        string prefix = strs[0];
        int len = prefix.length();

        for(int i=0; i<strs.size(); i++){
            while(len >0 && prefix.compare(0, len, strs[i].substr(0,len)) != 0)
                len--;
        }

        return prefix.substr(0,len);
    }
};
