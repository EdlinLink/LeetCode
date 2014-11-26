/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Spiral Matrix II 
    Source:     https://oj.leetcode.com/problems/spiral-matrix-ii/
    Note:

    Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

    For example,
    Given n = 3,

    You should return the following matrix:

        [
         [ 1, 2, 3 ],
         [ 8, 9, 4 ],
         [ 7, 6, 5 ]
        ]

    Solution:   Put value in a NxN matirx first. (Simple Simulation)
                Put matrix element into vector.
 */ 



class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {

        vector<vector<int> > myresult;

        int **num = new int *[n];
        for(int i=0; i<n; i++)
            num[i] = new int[n];

        int M = n;
        int N = n;

        int current = -1;
        int count = 1;
        long total = n*n;
        while(M>0 && N>0){
            for(int i=1; i<=N; i++){
                current++;
                num[current/n][current%n] = count++;
            }
            M--;
            if(!(M>0 && N>0))   break;

            for(int i=1; i<=M; i++){
                current+=n;
                num[current/n][current%n] = count++;
            }
            N--;
            if(!(M>0 && N>0))   break;

            for(int i=1; i<=N; i++){
                current--;
                num[current/n][current%n] = count++;
            }
            M--;
            if(!(M>0 && N>0))   break;

            for(int i=1; i<=M; i++){
                current-=n;
                num[current/n][current%n] = count++;
            }
            N--;
        }

        for(int i=0; i<n; i++){
            vector<int> v;
            for(int j=0; j<n; j++)
                v.push_back(num[i][j]);

            myresult.push_back(v);
        }

        for(int i=0; i<n; i++)
            delete [] num[i];
        delete []num;

        return myresult;
    }

};
