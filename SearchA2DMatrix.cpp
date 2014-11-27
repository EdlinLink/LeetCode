/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Search a 2D Matrix
    Source:     https://oj.leetcode.com/problems/set-matrix-zeroes/

    Write an efficient algorithm that searches for a value in an m x n matrix. 
    This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

    For example,

    Consider the following matrix:

        [
          [1,   3,  5,  7],
          [10, 11, 16, 20],
          [23, 30, 34, 50]
        ]

    Given target = 3, return true.

    Solution:   1.  Search from the top right corner  

 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int M = matrix.size();
        int N = 0;
        if(M!=0)
            N = matrix[0].size();

        if(M*N == 0)
            return false;

        int x = 0;
        int y = N-1;
        while(x<M && y>=0){
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target)
                y--;
            else
                x++;
        }
        return false;
    }
};
