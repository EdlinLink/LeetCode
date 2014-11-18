/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 17, 2014
    Problem:    Sudoku Solver 
    Source:     https://oj.leetcode.com/problems/sudoku-solver/
    Note:

    Write a program to solve a Sudoku puzzle by filling the empty cells.
    Empty cells are indicated by the character '.'.
    You may assume that there will be only one unique solution.

    Solution:   Backtracking

 */

#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
using namespace std;


class Solution {
public:
    
    bool Fixed[9][9];
    char B[9][9];
    bool found;

    bool V[9][9][9];

    void solveSudoku(vector<vector<char> > &board) {
    //void solveSudoku( string* board) {

        memset(Fixed, 0, sizeof(Fixed));
        memset(B, '.', sizeof(B));
        memset(V, 1, sizeof(V));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                B[i][j] = board[i][j];
                if(board[i][j] != '.'){
                    Fixed[i][j] = true;
                }
            }
        }

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(Fixed[i][j]){
                    int num = B[i][j] - '1';
                    for(int k=0; k<9; k++)
                        V[i][k][num] = false;
                    for(int k=0; k<9; k++)
                        V[i][k][num] = false;
                } 
            }
        }

        found = false;
        solve(0, 0);

        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                board[i][j] = B[i][j];
    }

    void solve(int x,int y){
        if(found)   return;

        if(Fixed[x][y] == true){
            if(x + (y+1)/9 == 9)
                found = true;

            solve(x+(y+1)/9, (y+1)%9);
        }
        else{
            char origin = B[x][y];
            for(int c=0; c<9 && !found; c++){
                if(V[x][y][c]==false)
                    continue;

                B[x][y] = c+'1';

                if(valid(x, y)){
                    if(x + (y+1)/9 == 9)
                        found = true;

                    solve(x+(y+1)/9, (y+1)%9);
                }
            }

            if(!found)
                B[x][y] = origin;
        }
    }

    bool valid(const int& x, const int& y){
        bool count[9];
        memset(count, 0, sizeof(count));
        for(int i=0; i<9; i++){
            if(B[i][y] == '.')
                continue;
            if(count[B[i][y]-'1']==true)
                return false;
            else
                count[B[i][y]-'1'] = true;
        }

        memset(count, 0, sizeof(count));
        for(int i=0; i<9; i++){
            if(B[x][i] == '.')
                continue;
            if(count[B[x][i]-'1']==true)
                return false;
            else
                count[B[x][i]-'1'] = true;
        }

        memset(count, 0, sizeof(count));
        for(int i=x/3*3; i<x/3*3 + 3; i++){
            for(int j=y/3*3; j<y/3*3 + 3; j++){
                if(B[i][j] == '.')
                    continue;
                if(count[B[i][j]-'1']==true)
                    return false;
                else
                    count[B[i][j]-'1'] = true;
            }
        }

        return true;
    }
};
