/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 25, 2014
    Problem:    N-Queens II 
    Source:     https://oj.leetcode.com/problems/n-queens-ii/
    Note:

    Follow up for N-Queens problem.
    Now, instead outputting board configurations, return the total number of distinct solutions.

    Solution:   Recursive
 */

class Solution {
public:
    int result;

    int totalNQueens(int n) {

        result = 0;
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
        result++;
    }
};