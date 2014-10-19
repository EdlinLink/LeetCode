/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 19, 2014
    Problem:    Integer to Roman 
    Source:     https://oj.leetcode.com/problems/integer-to-roman/
    Note:

    Given an integer, convert it to a roman numeral.
    Input is guaranteed to be within the range from 1 to 3999.

    Solution:   Just do it
                I, II, III, IV, V, VI, VII, VIII, IX, X     (Bits)
                X, XX, XXX, XL, L, LX, LXX, LXXX, XC, C     (Ten)
                C, CC, CCC, CD, D, DC, DCC, DCCC, CM, M     (Hundred)
                M, MM, MMM                                  (Thousand)
 */

class Solution {
public:

    string intToRoman(int num) {
        string Roman[4][10] = {
            "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", 
            "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
            "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
            "", "M", "MM", "MMM"
        };

        string roman = "";
        int index = 0;
        while(num!=0){
            roman = Roman[index][num%10] + roman;
            num /= 10; 
            index++;
        }
    
        return roman;
    }
};
