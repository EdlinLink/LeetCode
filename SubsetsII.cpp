/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Subsets II
    Source:     https://oj.leetcode.com/problems/subsets-ii/

    Given a collection of integers that might contain duplicates, S, return all possible subsets.

    Note:
    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
    For example,
    If S = [1,2,2], a solution is:

    [
      [2],
      [1],
      [1,2,2],
      [2,2],
      [1,2],
      []
    ]

    Solution:   Backtracking
 */

class Solution {
public:
    set<vector<int> >result;
    int n;

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        result.clear();
        n = S.size();
        sort(S.begin(), S.end());

        vector<int> v;
        result.insert(v);
        for(int i=0; i<n; i++){
            v.push_back(S[i]);
            result.insert(v);
            subset(v, S, i+1);
            v.pop_back();
        }

        vector<vector<int> > finalResult;
        for(set<vector<int> >::iterator it=result.begin(); it!=result.end(); it++)
            finalResult.push_back(*it);
        return finalResult;
    }

    void subset(vector<int> &v, vector<int> &S, int pos){
        if(pos >= n)    return;
        
        for(int i=pos; i<n; i++){
            v.push_back(S[i]);
            result.insert(v);
            subset(v, S, i+1);
            v.pop_back();
        }
    }
};
