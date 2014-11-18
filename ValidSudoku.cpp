/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 17, 2014
    Problem:    Valid Sudoku
    Source:     https://oj.leetcode.com/problems/valid-sudoku/
    Note:

    Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules(http://sudoku.com.au/TheRules.aspx).
    The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

    Note:

    A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

    Solution:   Counting the row, col, square validation of num frequency.
 */

class Solution {
public:
    
    bool isValidSudoku(vector<vector<char> > board) {
        bool freq[10];

        bool validation = true;
        for(int i=0; i<9 && validation; i++){
            memset(freq, 0, sizeof(freq));
            for(int j=0; j<9 && validation; j++){
                if(board[i][j] == '.')
                    continue;
                if(freq[board[i][j]-'0'] == true)
                    validation = false;
                else
                    freq[board[i][j]-'0'] = true;
            }
        }

        for(int i=0; i<9 && validation; i++){
            memset(freq, 0, sizeof(freq));
            for(int j=0; j<9 && validation; j++){
                if(board[j][i] == '.')
                    continue;
                if(freq[board[j][i]-'0'] == true)
                    validation = false;
                else
                    freq[board[j][i]-'0'] = true;
            }
        }

        for(int i=0; i<9 && validation; i+=3){
            for(int j=0; j<9 && validation; j+=3){
                memset(freq, 0, sizeof(freq));    
                for(int k=i; k<i+3 && validation; k++){        
                    for(int l=j; l<j+3 && validation; l++){
                        if(board[k][l] == '.')
                            continue;
                        if(freq[board[k][l]-'0'] == true)
                            validation = false;
                        else
                            freq[board[k][l]-'0'] = true;
                    }
                }
            }
        }

        return validation;
    }
};
