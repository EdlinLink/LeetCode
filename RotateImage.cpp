/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 25, 2014
    Problem:    Rotate Image
    Source:     https://oj.leetcode.com/problems/rotate-image/
    Note:

    You are given an n x n 2D matrix representing an image.
    Rotate the image by 90 degrees (clockwise).

    Follow up:
    Could you do this in-place?

    Solution:   Simulation
 */

class Solution {
public:

    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();

        for(int i=0; i<n/2; i++){
            rotateAt(matrix, i,i,n);
        }
    }

    void rotateAt(vector<vector<int> > &matrix, int x, int y, int N){
        for(int i=y; i<N-y-1; i++){
            swap(matrix, x, i, N);
        }
    }

    void swap(vector<vector<int> > &matrix, int x, int y, int N){
        int tmp = matrix[x][y];

        matrix[x][y] = matrix[N-1-y][x];
        matrix[N-1-y][x] = matrix[N-1-x][N-1-y];
        matrix[N-1-x][N-1-y] = matrix[y][N-1-x];
        matrix[y][N-1-x] = tmp;
    }
};