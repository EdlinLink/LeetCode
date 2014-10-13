/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 14, 2014
    Problem:    Longest Substring Without Repeating Characters 
    Source:     https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
    Note:

    Given a string, find the length of the longest substring without repeating characters.
    For example, the longest substring without repeating letters for "abcabcbb" is "abc",
    which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

    Solution:   1. Traval the string using two pointers to figure out the unique substring.
                2. Using the boolean array to record whether letter appear.

 */ 

#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool check[256];

    int lengthOfLongestSubstring(string s) {
        memset(check, 0, sizeof(check));
        
        int p_start = 0;
        int p_end = 0;
        int total = 0;

        int len = s.length();
        while(p_start < len && p_end < len){
            if(check[s[p_end]]==false){
                check[s[p_end]] = true;
                p_end++;
                if(p_end-p_start > total)
                    total = p_end - p_start;
            }
            else{
                while(check[s[p_end]]==true){
                    check[s[p_start]] = false;
                    p_start++;
                }
                check[s[p_end]] = true;
                p_end++;
            }
        }
        return total;
    }
};
