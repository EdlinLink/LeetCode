/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 15, 2014
    Problem:    Regular Expression Matching   
    Source:     https://oj.leetcode.com/problems/regular-expression-matching/
    Note:

    Implement regular expression matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "a*") → true
    isMatch("aa", ".*") → true
    isMatch("ab", ".*") → true
    isMatch("aab", "c*a*b") → true

    Solution:   1. Comparing normal letter A[0:] with B[0:] recursively.
                2. When meeting 'c*', comparing the A[+2:] and B[0:].

                Pay Attention:
                1. This is an exactly matching, not grep matching.
                2. Input(arg0="text", arg1="regular expression")
                3. If it is a grep matching, the comment in function isMatch should be removed.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    // s is text, p is regular expression
    bool isMatch(const char *s, const char *p) {
        char *grep = new char[strlen(p)+1];
        char *text = new char[strlen(s)+1];
        strcpy(grep, p);
        strcpy(text, s);
        char *p1 = grep;
        char *p2 = text;

        //do{
            if(matchhere(grep,text)){
                delete []p1;
                delete []p2;
                return 1;
            }
        //}while(*text++!='\0');

        delete []p1;
        delete []p2;
        return 0;
    }

    bool matchhere(char *grep, char *text){
        if(grep[0]=='\0')
            return 1;
        if(grep[1]=='*')
            return matchstar(grep[0], grep+2, text);
        
        if(text[0]!='\0' && (grep[0]=='.' || grep[0]==text[0]))
            return matchhere(grep+1, text+1);
        else
            return 0;
    }

    bool matchstar(char c, char *grep, char *text){
        do{
            if(matchhere(grep, text))
                return 1;
        }while(text[0]!='\0' && (c==*text++ || c=='.'));
        return 0;
    }
};
