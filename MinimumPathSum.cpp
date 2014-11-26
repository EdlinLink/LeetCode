/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Minimum Path Sum
    Source:     https://oj.leetcode.com/problems/minimum-path-sum/
    Note:

    Given a m x n grid filled with non-negative numbers, 
    find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Solution:   DP thought
 */ 

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = 0;
        if(m!=0)
            n = grid[0].size();

        int *num = new int[n];
        num[0] = grid[0][0];
        for(int i=1; i<n; i++)
            num[i] = num[i-1] + grid[0][i];

        for(int i=1; i<m; i++){
            num[0] += grid[i][0];
            for(int j=1; j<n; j++){
                num[j-1]<num[j] ? num[j]=grid[i][j]+num[j-1] : num[j]+=grid[i][j];
            }
        }

        int target = num[n-1];
        delete []num;
        return target;
    }
};
