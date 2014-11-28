/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 28, 2014
    Problem:    Subsets
    Source:     https://oj.leetcode.com/problems/subsets/

    Given a set of distinct integers, S, return all possible subsets.

    Note:
    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

    For example,
    If S = [1,2,3], a solution is:

    [
        [3],
        [1],
        [2],
        [1,2,3],
        [1,3],
        [2,3],
        [1,2],
        []
    ]

    Solution:   Similar to problem `Combinations`
 */

#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        int n = S.size();
        result.clear();

        vector<int> v;
        result.push_back(v);

        for(int i=0; i<n; i++){
            v.push_back(S[i]);
            result.push_back(v);
            comb(S, v, n, i+1);
            v.pop_back();
        }

        return result;
    }

    void comb(vector<int> &S, vector<int> &v, const int& n, const int& pos){
        for(int i=pos; i<n; i++){
            v.push_back(S[i]);
            result.push_back(v);
            comb(S, v, n, i+1);
            v.pop_back();
        }
    }
};
