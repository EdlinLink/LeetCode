/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 28, 2014
    Problem:    Word Search
    Source:     https://oj.leetcode.com/problems/word-search/

    Given a 2D board and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cell, 
    where "adjacent" cells are those horizontally or vertically neighboring. 
    The same letter cell may not be used more than once.

    For example,
    Given board =

        [
            ["ABCE"],
            ["SFCS"],
            ["ADEE"]
        ]

    word = "ABCCED", -> returns true,
    word = "SEE", -> returns true,
    word = "ABCB", -> returns false.

    Solution:   Use a bool matrix to record which grid has been visited.
 */

#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int M;
    int N; 
    bool **visited;
    int len;
    bool exist(vector<vector<char> > &board, string word) {
        M = board.size();
        N = 0;
        if(M!=0)
            N = board[0].size();

        visited = new bool*[M];
        for(int i=0; i<M; i++)
            visited[i] = new bool[N];

        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                visited[i][j] = false;

        len = word.size();
        if(len==0)
            return true;

        bool found = false;
        for(int i=0; i<M && !found; i++){
            for(int j=0; j<N && !found; j++){
                if(word[0] == board[i][j]){
                    visited[i][j] = true;
                    if(search(board, word, 1, i, j))
                        found = true;
                    visited[i][j] = false;
                }
            }
        }

        for(int i=0; i<M; i++)
            delete []visited[i];
        delete []visited;

        return found;
    }

    bool search(vector<vector<char> > &board, const string& word, int pos, int x, int y){
        if(pos == len)
            return true;

        if(x-1>=0 && visited[x-1][y]==false && board[x-1][y]==word[pos]){
            visited[x-1][y] = true;
            if(search(board, word, pos+1, x-1, y))
                return true;
            visited[x-1][y] = false;
        }

        if(x+1<M && visited[x+1][y]==false && board[x+1][y]==word[pos]){
            visited[x+1][y] = true;
            if(search(board, word, pos+1, x+1, y))
                return true;
            visited[x+1][y] = false;
        }

        if(y-1>=0 && visited[x][y-1]==false && board[x][y-1]==word[pos]){
            visited[x][y-1] = true;
            if(search(board, word, pos+1, x, y-1))
                return true;
            visited[x][y-1] = false;
        }

        if(y+1<N && visited[x][y+1]==false && board[x][y+1]==word[pos]){
            visited[x][y+1] = true;
            if(search(board, word, pos+1, x, y+1))
                return true;
            visited[x][y+1] = false;
        }

        return false;
    }
};

int main(){
    Solution s;

    std::vector<std::vector<char> > V;
    std::vector<char> v;
    v.push_back('a');
    v.push_back('b');
    V.push_back(v);

    v.clear();
    v.push_back('c');
    v.push_back('d');
    V.push_back(v);
    s.exist(V, "abcd");
    return 0;
}
