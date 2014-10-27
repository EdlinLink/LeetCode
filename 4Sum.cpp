/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 27, 2014
    Problem:    4Sum
    Source:     https://oj.leetcode.com/problems/4sum/
    Note:

    Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
    Find all unique quadruplets in the array which gives the sum of target.

    Note:
    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

         For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
         A solution set is:
         (-1,  0, 0, 1)
         (-2, -1, 1, 2)
         (-2,  0, 0, 2)

    Solution:   Time complexity O(n^3)
                It seems that there is O(n^2) solution, please see the reference.

    Reference:  http://tech-wonderland.net/blog/summary-of-ksum-problems.html
 */

#include <set>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector <vector<int> > result;
        sort(num.begin(), num.end());

        if(num.size() < 4)
            return result;

        for(int i=0; i < num.size(); i++){
            while(i>0 && num[i]==num[i-1])
                i++;

            for(int j=i+1; j < num.size(); j++){
                while(j>i+1 && num[j]==num[j-1])
                    j++;

                int k = j+1;
                int l = num.size()-1;

                while(i<j && j<k && k<l){
                    while(k>j+1 && num[k]==num[k-1])
                        k++;
                    while(l<num.size()-1 && num[l]==num[l+1])
                        l--;

                    if(i<j && j<k && k<l){
                        if(num[i]+num[j]+num[k]+num[l] == target){
                            vector<int> v;
                            v.push_back(num[i]);
                            v.push_back(num[j]);
                            v.push_back(num[k]);
                            v.push_back(num[l]);
                            result.push_back(v);
                            l--;
                            k++;
                        }
                        else if(num[i]+num[j]+num[k]+num[l] < target){
                            k++;
                        }
                        else{
                            l--;
                        }
                    }
                }

            }

        }

        return result;
    }    
};