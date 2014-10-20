/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 20, 2014
    Problem:    3Sum
    Source:     https://oj.leetcode.com/problems/3sum/
    Note:

    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
    Find all unique triplets in the array which gives the sum of zero.

    Note:
    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

        For example, given array S = {-1 0 1 2 -1 -4},
        A solution set is:
        (-1, 0, 1)
        (-1, -1, 2)

    Solution:   Time complexity O(n^2)
                The most important thing is how to prevent the duplicate.
                
                key code:

                if(b>a+1 && *b==*(b-1)){
                    b++;
                    continue;
                }
                if(c<num.end()-1 && *c==*(c+1)){
                    c--;
                    continue;
                }

    Reference:  http://blog.csdn.net/xshalk/article/details/8148422
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;

        vector<int>::iterator a, b, c;
        vector<int> v;

        for(a = num.begin(); a<num.end(); a++){

            b = a + 1;
            c = num.end() - 1;

            while(b < c){
                if(b>a+1 && *b==*(b-1)){
                    b++;
                    continue;
                }
                if(c<num.end()-1 && *c==*(c+1)){
                    c--;
                    continue;
                }

                if(*a + *b + *c == 0){
                    v.clear();
                    v.push_back(*a);
                    v.push_back(*b);
                    v.push_back(*c);
                    result.push_back(v);
                    b++;
                    c--;
                }
                else if(*a + *b + *c < 0)
                    b++;
                else
                    c--;
            }

            while(*a == *(a+1) && a<num.end())
                a++;

        }
        return result;
    }    
};
