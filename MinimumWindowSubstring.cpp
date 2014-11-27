/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Minimum Window Substring
    Source:     https://oj.leetcode.com/problems/minimum-window-substring/

    Given a string S and a string T, 
    find the minimum window in S which will contain all the characters in T in complexity O(n).

    For example,
    S = "ADOBECODEBANC"
    T = "ABC"
    Minimum window is "BANC".

    Note:
    If there is no such window in S that covers all characters in T, return the emtpy string "".
    If there are multiple such windows, 
    you are guaranteed that there will always be only one unique minimum window in S.

    Solution:   1.  Counting the unique character in T
                2.  Record the 'we-need' character in S in countS
                3.  We get the start_index and end_index
                4.  We can move start_index, if there still satisfy the MinWin require, else move end_index

 */
#include <string>
#include <stack>
#include <iostream>
#define ASCII 128

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        stack<int> s;

        //  Counting the unique character in T
        int countT[ASCII];
        for(int i=0; i<ASCII; i++)
            countT[i] = 0;

        for(int i=0; i<T.size(); i++)
            countT[ T[i] ]++;

        int unique = T.size();

        //  Find the start position
        int countS[ASCII];
        for(int i=0; i<ASCII; i++)
            countS[i] = 0;

        int start = -1;
        int end;
        int collect = 0;
        for(int i=0; i<S.size(); i++){
            if(countT[ S[i] ] > 0){
                countS[ S[i] ]++;
                collect++;
                start = i;
                end = i+1;
                break;
            }
        }

        if(start == -1)
            return "";

        while(start<S.size() || end<S.size()){
            if(collect == unique){
                s.push(start);      //push start position
                s.push(end-start);  //push window length
            }

            if(countT[S[start]] == 0)
                start++;
            else if(countT[S[start]] && countS[S[start]] > countT[S[start]]){
                countS[ S[start] ]--;
                start++;
            }
            else if(end<S.size()){
                if(countT[ S[end] ]){
                    if(countS[ S[end] ] < countT[ S[end] ])
                        collect++;
                    countS[ S[end] ]++;
                }
                end++;
            }
            else if(start<S.size()){
                if(countS[S[start]]){
                    if(countS[S[start]] <= countT[ S[start] ])
                        collect--;
                    countS[ S[start] ]--;
                }
                start++;
            }
            else
                break;
        }

        if(s.empty())
            return "";
        int min_len = s.top();
        s.pop();
        start = s.top();
        s.pop();
        
        while(!s.empty()){
            if(s.top() < min_len){
                min_len = s.top();
                s.pop();
                start = s.top();
                s.pop();
            }
            else{
                s.pop();
                s.pop();
            }
        }

        return S.substr(start, min_len);

    }
};

int main(){
    Solution s;
    cout<<s.minWindow("cabefgecdaecf", "cae")<<endl;
    return 0;
}
