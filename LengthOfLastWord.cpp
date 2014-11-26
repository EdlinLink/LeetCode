/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Length of Last Word 
    Source:     https://oj.leetcode.com/problems/length-of-last-word/
    Note:

    Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
    return the length of last word in the string.

    If the last word does not exist, return 0.

    Note: A word is defined as a character sequence consists of non-space characters only.

        For example, 
        Given s = "Hello World",
        return 5.

    Solution:   Simulation
 */ 



class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(*s == NULL || *s == '\0')
            return 0;

        int index = 0;
        char *p = (char *)s;
        while(*p!='\0'){
            if(*p == ' '){
                if(*(p+1)!='\0' && *(p+1)!=' ')    
                    index = 0;
            }
            else
                index++;

            p++;
        }
        return index;
    }

};
