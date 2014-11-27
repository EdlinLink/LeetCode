/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 28, 2014
    Problem:    Combinations 
    Source:     https://oj.leetcode.com/problems/combinations/

    Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

    For example,
    If n = 4 and k = 2, a solution is:

        [
            [2,4],
            [3,4],
            [2,3],
            [1,2],
            [1,3],
            [1,4],
        ]

    Solution:   Backtracking
 */


class Solution {
public:
    vector<vector<int> > result;

    vector<vector<int> > combine(int n, int k) {
        result.clear();

        vector<int> v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
            comb(v, n, k, 1, i);
            v.pop_back();
        }

        return result;
    }

    void comb(vector<int> &v, const int& n, const int& k, const int& len, const int& last){
        if(len == k){
            result.push_back(v);
            return;
        }

        for(int i=last+1; i<=n; i++){
            v.push_back(i);
            comb(v, n, k, len+1, i);
            v.pop_back();
        }
    }
};
