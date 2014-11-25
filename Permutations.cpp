/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 25, 2014
    Problem:    Permutations  
    Source:     https://oj.leetcode.com/problems/permutations/
    Note:

    Given a collection of numbers, return all possible permutations.

    For example,
    [1,2,3] have the following permutations:
    [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

    Solution:   Backtracking
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:


    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size()==0)
            return result;

        sort(num.begin(), num.end());
        result.push_back(num);

        int len = num.size();

        while(true){
            bool found = false;
            int max_index = len-1;

            for(int i=len-2; i>=0; i--){
                if(num[i] < num[max_index]){
                    int larger_index = max_index;
                    for(int j=i+1; j<len; j++){
                        if(num[j] > num[i] && num[j] < num[larger_index])
                            larger_index = j;
                    }
                    swap(num[larger_index], num[i]);
                    sort(num.begin()+i+1, num.end());
                    result.push_back(num);
                    found = true;
                    break;
                }
                else
                    max_index = i;
            }

            if(!found)  break;
        }
        return result;
    }

    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};