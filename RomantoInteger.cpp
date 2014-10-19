/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 19, 2014
    Problem:    Roman to Integer
    Source:     https://oj.leetcode.com/problems/roman-to-integer/
    Note:

    Given a roman numeral, convert it to an integer.
    Input is guaranteed to be within the range from 1 to 3999.

    Solution:   1. Scan the string from right to left and adding the letter represent num
                2. If the letter represent num is decresing, it should be minus not add
                3. For example:

                    VIII(8) = (1)+(1)+(1)+(5) = 8  no decrease.
                    LXXIX(79) = (10)-(1)+(10)+(10)+(50) = 79    'I' make the sequence decrese.    


                I, II, III, IV, V, VI, VII, VIII, IX, X     (Bits)
                X, XX, XXX, XL, L, LX, LXX, LXXX, XC, C     (Ten)
                C, CC, CCC, CD, D, DC, DCC, DCCC, CM, M     (Hundred)
                M, MM, MMM                                  (Thousand)
 */

#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> r2i;
        r2i['I'] = 1 ;
        r2i['V'] = 5;
        r2i['X'] = 10;
        r2i['L'] = 50;
        r2i['C'] = 100;
        r2i['D'] = 500;
        r2i['M'] = 1000;

        int index = s.length()-1;
        int represent_num = r2i[ s[index] ];
        int integer = represent_num;

        while(index--){
            int num = r2i[ s[index] ];
            if(num < represent_num)
                integer -= num;
            else
                integer += num;

            represent_num = num;
        }

        return integer;
    }
};
