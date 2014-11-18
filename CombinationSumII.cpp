/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 18, 2014
    Problem:    Combination Sum II
    Source:     https://oj.leetcode.com/problems/combination-sum-ii/
    Note:

    Given a collection of candidate numbers (C) and a target number (T), 
    find all unique combinations in C where the candidate numbers sums to T.

    Each number in C may only be used once in the combination.

    Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

    For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
    A solution set is: 

        [1, 7] 
        [1, 2, 5] 
        [2, 6] 
        [1, 1, 6] 

    Solution:   Backtracking

 */

#include <stack>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        set<vector<int> > set_result;
        vector<int> v;
        stack<int> s;

        int index = 0;
        int len = candidates.size();
        int sum = 0;
        sort(candidates.begin(), candidates.end());

        do{
            while(sum < target && index < len){
                v.push_back(candidates[index]);
                s.push(index);
                sum += candidates[index];
                index++;
            }

            if(sum == target)
                set_result.insert(v);

            while((sum >= target || index >= len) && (v.size() > 0)){
                sum -= v.back();
                v.pop_back();
                index = s.top()+1;
                s.pop();
            }

        }while(!v.empty() || !(index>=len) );

        for(set<vector<int> >::iterator it = set_result.begin(); it!=set_result.end(); it++)
            result.push_back(*it);
        return result;
    }
};
