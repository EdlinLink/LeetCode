/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 27, 2014
    Problem:    Simplify Path 
    Source:     https://oj.leetcode.com/problems/simplify-path/
    Note:

    Given an absolute path for a file (Unix-style), simplify it.

    For example,
    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"

    Solution:   1.  Use a stack to record the folder
                2.  if command is '.', do nothing;
                3.  if command is '..', pop()
 */ 

#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        stack<string> s;
        path += '/';

        int start;
        int end = 0;
        while(end < path.size()){
            start = end;
            end++;

            bool found = false;
            while(end < path.size()){
                if(path[end]=='/'){
                    found = true;
                    break;
                }
                end++;
            }

            if(!found){
                while(!s.empty()){
                    result = s.top()+result;
                    s.pop();
                }
                if(result == "")
                    return "/";
                return result;
            }

            string content = path.substr(start, end-start);

            if(content == "/" || content == "/." || content == "" )
                ;
            else if(content == "/.." && !s.empty()) 
                s.pop();
            else
                s.push(content);
        }

    }
};

