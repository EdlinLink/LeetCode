/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 9, 2014
    Problem:    Longest Palindromic Substring 
    Source:     https://oj.leetcode.com/problems/longest-palindromic-substring/
    Note:

    Given a string S, find the longest palindromic substring in S. 
    You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

    Solution:   Manacher's Algorithm
                http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
                The link is about the algorithm and the time complexity O(n) is discuss in the comment.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string sub = "";
        int len = Manacher(s, sub);
        return sub;
    }

    int *P;
    int bound;
    int axis;

    int Manacher(string origin, string &sub){
        string s = Preprocess(origin);
        
        for(int i=1; i<s.length(); i++){
            if(bound > i){
                if(bound-i < P[2*axis-i])
                    P[i] = bound-i;
                else
                    P[i] = P[2*axis-i];
            }

            while(s[ i+P[i] ] == s[ i-P[i] ])
                P[i]++;

            if(i+P[i] > bound){
                bound = i+P[i];
                axis = i;
            }
        }

        int max = 0;
        int index = 0;
        for(int i=0; i<s.length(); i++){
            if(P[i] > max){
                max = P[i];
                index = i;
            }
        }

        sub = "";
        for(int i=index-max+1; i<index+max-1; i++)
            if(s[i]!='#')
                sub+=(s[i]);
        return max;
    }

    string Preprocess(string s){
        bound = 0;
        axis = 0;

        string post = "$#";
        int len = s.length();
        for(int i=0; i<len; i++){
            post+=(s[i]);
            post+=("#");
        }

        P = new int[post.length()];
        for(int i=0; i<post.length(); i++)
            P[i] = 0;

        return post;
    }
};