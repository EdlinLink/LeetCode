/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 15, 2014
    Problem:    ZigZag Conversion  
    Source:     https://oj.leetcode.com/problems/zigzag-conversion/
    Note:

    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
    (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

    And then read line by line: "PAHNAPLSIIGYIR"
    
    Write the code that will take a string and make this conversion given a number of rows:

        string convert(string text, int nRows);
    
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

    Solution:   Simulate directly
                1. N string representing N rows.
                2. Join all string.
 */

class Solution {
public:
    string convert(string s, int nRows) {

        if(nRows==1)
            return s;

        string *Row = new string[nRows];
        int i=0;
        int row=0;
        int len = s.length();
        while(i<len){
            while(row < nRows-1 && i<len){
                Row[row]+=s[i];
                row++;
                i++;
            }

            while(row > 0 && i<len){
                Row[row]+=s[i];
                row--;
                i++;
            }
        }

        for(int i=1; i<nRows; i++)
            Row[0]+=Row[i];

        return Row[0];
    }
};
