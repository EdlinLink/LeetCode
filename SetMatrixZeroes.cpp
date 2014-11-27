/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Set Matrix Zeroes 
    Source:     https://oj.leetcode.com/problems/set-matrix-zeroes/

    Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

    Solution:   1.  Record the position of 0
                2.  Update the matrix

 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        stack<int> s;
        int M = matrix.size();
        int N = 0;
        if(M!=0)
            N = matrix[0].size();

        if(M*N==0)
            return;

        int min = matrix[0][0];
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(0 == matrix[i][j]){
                    s.push(i);
                    s.push(j);
                }
            }
        }

        while(!s.empty()){
            int y = s.top();
            s.pop();
            int x = s.top();
            s.pop();

            for(int i=0; i<M; i++)
                matrix[i][y] = 0;
            for(int i=0; i<N; i++)
                matrix[x][i] = 0;
        }
    }
};
