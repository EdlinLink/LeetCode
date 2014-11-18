/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 18, 2014
    Problem:    Combination Sum 
    Source:     https://oj.leetcode.com/problems/combination-sum/
    Note:

    Given a set of candidate numbers (C) and a target number (T),
    find all unique combinations in C where the candidate numbers sums to T.

    The same repeated number may be chosen from C unlimited number of times.

    Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

        For example, given candidate set 2,3,6,7 and target 7, 

        A solution set is: 
        [7] 
        [2, 2, 3] 

    Solution:   Backtracking

 */

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> v;
        stack<int> s;

        int index = 0;
        int len = candidates.size();
        int sum = 0;
        sort(candidates.begin(), candidates.end());

        do{
            while(sum < target){
                v.push_back(candidates[index]);
                s.push(index);
                sum += candidates[index];
            }

            if(sum == target)
                result.push_back(v);

            while((sum >= target || index >= len) && (v.size() > 0)){
                sum -= v.back();
                v.pop_back();
                index = s.top()+1;
                s.pop();
            }

        }while(!v.empty() || !(index>=len) );

        return result;
    }
};
