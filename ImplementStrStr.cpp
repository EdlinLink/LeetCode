/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 3, 2014
    Problem:    Implement strStr() 
    Source:     https://oj.leetcode.com/problems/implement-strstr/
    
    Note:       
    Implement strStr().
    Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Update (2014-11-02):
    The signature of the function had been updated to return the index instead of the pointer. 
    If you still see your function signature returns a char * or String, 
    please click the reload button  to reset your code definition.

    Solution:   KMP Algorightm.
                
                Trick:
                1. STL vector is slow, use new() instead of vector.
                2. Normal KMP will be TLE, try to check the last letter first.

 */
                
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int haystack_len = strlen(haystack);
        int needle_len = strlen(needle);

        if(haystack_len < needle_len)
            return -1;

        if(needle == NULL || needle_len==0)
            return 0;


        int *P = new int[needle_len+1];

        P[0] = -1;
        P[1] = 0;

        int i=0;
        while(++i < needle_len){
            if(needle[P[i]] == needle[i])
                P[i+1] = P[i]+1;
            else
                P[i+1] = 0;
        }

        i = 0;
        while(i+needle_len <= haystack_len){
            int j = 0;

            // Try to check the last letter.
            if(needle[needle_len-1] != haystack[i+needle_len-1]){
                i++;
                continue;
            }

            while(i+j<haystack_len && j<needle_len && haystack[i+j] == needle[j]){
                j++;
            }

            if(j == needle_len){
                delete []P;
                return i;
            }
            else
                i+= (j - P[j]);
        }

        delete []P;
        return -1;
    }
};
