/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Permutation Sequence 
    Source:     https://oj.leetcode.com/problems/permutation-sequence/
    Note:

    The set [1,2,3,…,n] contains a total of n! unique permutations.

    By listing and labeling all of the permutations in order,
    We get the following sequence (ie, for n = 3):

        1   "123"
        2   "132"
        3   "213"
        4   "231"
        5   "312"
        6   "321"

    Given n and k, return the kth permutation sequence.

    Note: Given n will be between 1 and 9 inclusive.

    Solution:   Given a num abc, for example: 231, 'a' can be less than '2'.
                If a < 2, (1), there will be total 1*2! num less than 231.
                If b < 3, (1), there will be total 1*1! num less than 231.
                If c < 1, no other choice, there will be total 0 num less than 231.
                `231` is the 1*2!+1*1!+0 = 3 number index from 0,
                so `231` is the 4 number index from 1.
 */ 

class Solution {
public:
    bool num[10];

    string getPermutation(int n, int k) {
        memset(num, 0, sizeof(num));
        string result = "";
        int i = 1;
        k--;
        while(k!=0){
            long factorial = Factorial(n-i);
            result += useNthMin(k/factorial, n);
            k %= factorial;
            i++;
        }

        while(result.size() < n)
            result += useNthMin(0, n);

        return result;
    }

    char useNthMin(int x, int n){
        int count = 0;
        for(int i=1; i<=n; i++){
            if(num[i] == false){
                if(count == x){
                    num[i] = true;
                    return i+'0';
                }
                count++;
            }
        }
        return 'x';
    }

    long Factorial(int x){
        //if(x==0)    return 0;
        long result = 1;
        while(x!=0){
            result *= x;
            x--;
        }
        return result;
    }
};
