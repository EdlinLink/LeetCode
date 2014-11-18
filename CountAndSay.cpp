/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 18, 2014
    Problem:    Count and Say 
    Source:     https://oj.leetcode.com/problems/count-and-say/
    Note:

    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...

    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.

    Note: The sequence of integers will be represented as a string.

    Solution:   Just do it.

 */

class Solution {
public:

    string countAndSay(int n) {
        string result = "1";
        while(--n)
            countSay(result);
        return result;
    }

    void countSay(string& n) {

        int len = n.size();
        string result = "";
        char c = ' ';
        int count;
        for(int i=0; i<len; i++){
            if(i==0){
                c = n[i];
                count = 0;
            }

            if(n[i] == c){
                count++;
            }
            else{
                result += (Int2String(count) + c);
                c = n[i];
                count = 1;
            }
        }
        result += (Int2String(count) + c);
        n = result;
    }

    string Int2String(int num){
        string result = "";
        if(num==0){
            return "0";
        };
        while(num!=0){
            result = char(num%10 +'0') + result;
            num/=10;
        }
        return result;
    }
};