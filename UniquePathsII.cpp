/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Unique Paths II
    Source:     https://oj.leetcode.com/problems/unique-paths-ii/
    Note:

    Follow up for "Unique Paths":
    Now consider if some obstacles are added to the grids. How many unique paths would there be?
    An obstacle and empty space is marked as 1 and 0 respectively in the grid.

    For example,
    There is one obstacle in the middle of a 3x3 grid as illustrated below.

    [
     [0,0,0],
     [0,1,0],
     [0,0,0]
    ]

    The total number of unique paths is 2.

    Note: m and n will be at most 100.

    Solution:   DP thought
 */ 


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = 0;
        if(m!=0)
            n = obstacleGrid[0].size();

        int *path = new int[n];

        int i=0; 
        for(; i<n && obstacleGrid[0][i]==0; i++)
            path[i] = 1;
        for(; i<n; i++)
            path[i] = 0;

        for(int i=1; i<m; i++){
            if(obstacleGrid[i][0]==1)
                path[0] = 0;
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1)
                    path[j] = 0;
                else
                    path[j] = path[j-1]+path[j];
            }
        }

        int target = path[n-1];
        delete []path;
        return target;
    }
};
