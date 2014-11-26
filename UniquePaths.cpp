/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Unique Paths 
    Source:     https://oj.leetcode.com/problems/unique-paths/
    Note:

    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
    The robot can only move either down or right at any point in time. 
    The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?

    Solution:   DP thought
 */ 

class Solution {
public:
    int uniquePaths(int m, int n) {
        int *path = new int[n];
        for(int i=0; i<n; i++)
            path[i] = 1;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++)
                path[j] = path[j-1]+path[j];
        }

        int target = path[n-1];
        delete []path;
        return target;
    }
};