/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Decode Ways
    Source:     https://oj.leetcode.com/problems/decode-ways/

    A message containing letters from A-Z is being encoded to numbers using the following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26

    Given an encoded message containing digits, determine the total number of ways to decode it.

    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

    The number of ways decoding "12" is 2.

    Solution:   DP
                way[i] = way[i-2]+way[i-1] when 10<=(i-1)(i)<=26
                pay attention to 0
 */

class Solution {
public:
    int numDecodings(string s) {

        if(invalid(s))
            return 0;

        if(s.size()==1) return 1;

        int *way = new int[s.size()];
        for(int i=0; i<s.size(); i++)
            way[i] = 0;

        way[0] = 1;

        for(int i=1; i<s.size(); i++){
            if(i+1<s.size() && s[i+1]=='0')
                way[i] = way[i-1];
            else if((s[i-1]=='1' && '1'<=s[i] && s[i]<='9') || (s[i-1]=='2' && '1'<=s[i] && s[i]<='6')){
                if(i==1)    way[i] = 2;
                else        way[i] = way[i-2] + way[i-1];
            }
            else
                way[i] = way[i-1];
        }

        int target = way[s.size()-1];
        delete []way;
        return target;
    }

    bool invalid(string s){
        if(s=="" || s[0]=='0')
            return true;
        for(int i=1; i<s.size(); i++)
            if(s[i]=='0' && (s[i-1]!='1' && s[i-1]!='2'))
                return true;
        return false;

    }
};