/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 15, 2014
    Problem:    Valid Number 
    Source:     https://oj.leetcode.com/problems/valid-number/
    Note:

    Validate if a given string is numeric.

    Some examples:
    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true

    Note: It is intended for the problem statement to be ambiguous. 
    You should gather all requirements up front before implementing one.
 
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        if(s == NULL)   return false;

        int len = 0;
        while(s[len]!='\0')
            len++;

        int padding = 0;
        while(padding<len && s[padding]==' ')
            padding++;
        int start = padding;

        padding = len-1;
        while(padding>=0 && s[padding]==' ')
            padding--;
        int end = padding;

        //  finding 'e'
        int e_index = -1;
        for(int i=start; i<=end; i++){
            if(s[i]=='e'){
                e_index = i;
                break;
            }
        }

        if(e_index!=-1){
            if(!frequenceValid(s, start, e_index-1) || !frequenceValid(s, e_index+1, end, 0))
                return false;
        }
        else{
            if(!frequenceValid(s, start, end))
                return false;
        }

        return true;
    }

    bool frequenceValid(const char* s, int start, int end, bool point_count = 1){
        int plus = false;
        int minus = false;
        int point = false;
        int num = false;

        for(int i=start; i<=end; i++){
            if(s[i] == '+'){
                plus++;
                if(i!=start)    return false;
            }
            else if(s[i] == '-'){
                minus++;
                if(i!=start)    return false;
            }
            else if(s[i] == '.')                point++;
            else if('0'<=s[i] && s[i]<='9')     num++;
            else                                return false;
        }

        if(num==0)                      return false;
        else if(plus+minus>1)           return false;
        else if(point > point_count)    return false;
        else                            return true;
    }
};
