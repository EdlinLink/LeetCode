/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 25, 2014
    Problem:    N-Queens
    Source:     https://oj.leetcode.com/problems/n-queens/
    Note:

    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle.
    Each solution contains a distinct board configuration of the n-queens' placement, 
    where 'Q' and '.' both indicate a queen and an empty space respectively.

    For example,
    There exist two distinct solutions to the 4-queens puzzle:

        [
         [".Q..",  // Solution 1
          "...Q",
          "Q...",
          "..Q."],

         ["..Q.",  // Solution 2
          "Q...",
          "...Q",
          ".Q.."]
        ]

    Solution:   Recursive
 */

class Solution {
public:
    vector<vector<string> > result;

    vector<vector<string> > solveNQueens(int n) {
        result.clear();
        int *pos = new int[n];

        putQueen(pos, 0, n);
        delete []pos;

        return result;
    }

    void putQueen(int* pos, int line, int N){
        if(line >= N){
            takeRecord(pos, N);
            return;
        }

        for(int i=0; i<N; i++){
            pos[line] = i;
            if(valid(pos, line, N))
                putQueen(pos, line+1, N);
        }
    }

    bool valid(int* pos, int line, int N){
        for(int i=0; i<=line; i++){
            for(int j=1; j<=line-i; j++){
                if(pos[i]+j==pos[i+j] || pos[i]==pos[i+j] || pos[i]-j==pos[i+j])
                    return false;
            }
        }
        return true;
    }

    void takeRecord(int* pos, int N){
        string line = "";
        for(int i=0; i<N; i++)
            line+='.';

        vector<string> v;
        for(int i=0; i<N; i++){
            string tmp = line;
            tmp[pos[i]] = 'Q';
            v.push_back(tmp);
        }

        result.push_back(v);
    }
};




