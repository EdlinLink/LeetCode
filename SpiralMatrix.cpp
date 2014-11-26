/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Spiral Matrix 
    Source:     https://oj.leetcode.com/problems/spiral-matrix/
    Note:

    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

    For example,
    Given the following matrix:

        [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
        
    You should return [1,2,3,6,9,8,7,4,5].

    Solution:   Simulation
                `current` represent the position index of matrix
                
                    [ 0, 1, 2, ..., n-1 ],
                    [ n, n+1, ..., 2n-1 ], 
                    ......
                    [(m-1)n, ...,  mn-1 ]

                calculate the position (x,y) by (current/N, current%N).

 */             

class Solution {
public:
    vector<int> result;
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        result.clear();
        int m = matrix.size();
        int n = 0;
        if(m!=0)
            n = matrix[0].size();

        int N = n;
        int current = -1;
        while(m>0 && n>0){
            for(int i=1; i<=n; i++){
                current++;
                result.push_back(matrix[current/N][current%N]);
            }
            m--;

            if(!(m>0 && n>0))    break;

            for(int i=1; i<=m; i++){
                current+=N;
                result.push_back(matrix[current/N][current%N]);
            }
            n--;

            if(!(m>0 && n>0))    break;

            for(int i=1; i<=n; i++){
                current--;
                result.push_back(matrix[current/N][current%N]);
            }
            m--;

            if(!(m>0 && n>0))    break;

            for(int i=1; i<=m; i++){
                current-=N;
                result.push_back(matrix[current/N][current%N]);
            }
            n--;
        }

        return result;
    }
};
