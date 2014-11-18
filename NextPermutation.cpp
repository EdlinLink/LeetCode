/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 17, 2014
    Problem:    Next Permutation  
    Source:     https://oj.leetcode.com/problems/next-permutation/
    Note:

    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

    The replacement must be in-place, do not allocate extra memory.

    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1

    Solution:   For an integer abcd.
                The next permutation is to see its last num digit.
                if (c<d), exchange (c,d), "abdc" will be quite a little bigger integer than "abcd".
                if (c>d), than we have to check last 3 num digit. Find a least bigger integer.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() < 2)      return;

        int len = num.size();        
        int index = len-1;

        bool found = false;

        for(int i=len-1; i>=0; i--){
            if(num[i] < num[index]){
                found = true;
                for(int j=i+1; j<len; j++){
                    if(num[j]>num[i] && num[j]<num[index])
                        index = j;
                }
                swap(num[i], num[index]);
                sort(num.begin()+i+1, num.end());
                break;
            }
            else
                index = i;
        }

        if(!found){
            sort(num.begin(), num.end());
        }
    }

    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};