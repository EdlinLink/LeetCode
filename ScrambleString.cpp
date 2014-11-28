/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Scramble String
    Source:     https://oj.leetcode.com/problems/scramble-string/

    Given a string s1, 
    we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

    Below is one possible representation of s1 = "great":

        great
       /    \
      gr    eat
     / \    /  \
    g   r  e   at
               / \
              a   t

    To scramble the string, we may choose any non-leaf node and swap its two children.
                                   
    For example, 
    if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

        rgeat
        /    \
       rg    eat
      / \    /  \
     r   g  e   at
                / \
               a   t
    
    We say that "rgeat" is a scrambled string of "great".

    Similarly, if we continue to swap the children of nodes "eat" and "at", 
    it produces a scrambled string "rgtae".

        rgtae
        /    \
       rg    tae
      / \    /  \
     r   g  ta  e
            / \
           t   a
    
    We say that "rgtae" is a scrambled string of "great".

    Given two strings s1 and s2 of the same length, 
    determine if s2 is a scrambled string of s1.

    Solution:   1.  Cut the string into two part
                2.  recursive determine whether they are scrambled
 */

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1=="")  return true;
        if(s1==s2)  return true;

        bool reverse = true;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[s2.size()-1-i]){
                reverse = false;
                break;
            }
        }
        if(reverse)
            return true;


        for(int i=s1.size()-1; i>=1; i--){
            if(sameLetter(s1.substr(0,i), s2.substr(0,i))){
                if( isScramble(s1.substr(0,i), s2.substr(0,i)) && 
                        isScramble(s1.substr(i,s1.size()), s2.substr(i,s1.size())) )
                  return true;
            }
            else if(sameLetter(s1.substr(0,i), s2.substr(s2.size()-i,i))){
                if( isScramble(s1.substr(0,i), s2.substr(s2.size()-i,i)) && 
                        isScramble(s1.substr(i,s1.size()-i), s2.substr(0,s1.size()-i)) )
                  return true;
            }
        }
        return false;
    }

    bool sameLetter(string s1, string s2){
        sort(&s1[0], &s1[s1.size()]);
        sort(&s2[0], &s2[s2.size()]);
        if(s1==s2)  return true;
        else        return false;
    }
};

int main(){
  Solution s;
  cout<<s.isScramble("cbccbcbcacaaaaaa", "cabaabcaaacaccbc")<<endl;
  return 0;
}
