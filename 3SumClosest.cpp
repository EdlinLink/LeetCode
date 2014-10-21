/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 21, 2014
    Problem:    3Sum Closest
    Source:     https://oj.leetcode.com/problems/3sum-closest/
    Note:

    Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
    Return the sum of the three integers. You may assume that each input would have exactly one solution.

        For example, given array S = {-1 2 1 -4}, and target = 1.
        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

    Solution:   Same solution to 3Sum problem
 */

#include <algorithm>
#include <vector>
#include <iostream>
#define INF 999999
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        int closest = INF;
        int distance = INF;
        int sum;
        vector<int>::iterator a, b, c;

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
    
                sum = *a + *b + *c;

                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    if(distance > target - sum){
                        closest =  sum;
                        distance = target - sum;
                    }
                    b++;
                }
                else{
                    if(distance > sum - target){
                        closest = sum;
                        distance = sum - target;
                    }
                    c--;
                }
            }

            while(*a == *(a+1) && a<num.end())
                a++;

        }
        return closest;
    }    
};

int main(){
    Solution s;
    std::vector<int> v;
    v.push_back(-3);
        v.push_back(0);
            v.push_back(1);
            v.push_back(2);
           cout<< s.threeSumClosest(v,1);
    return 0;
}
