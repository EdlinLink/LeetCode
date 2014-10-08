/*
	Author:		Edlin(LIN Junhao) edlinlink@qq.com
	Date:		Oct. 9, 2014
	Problem:	Two Sum
	Source:		https://oj.leetcode.com/problems/two-sum/
	Note:

	Given an array of integers, find two numbers such that they add up to a specific target number.

	The function twoSum should return indices of the two numbers such that they add up to the target, 
	where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.

	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2

	Solution:	1. Sort the vector
				2. Two pointers pointing to the first element and the last one.
				3. Narrow down the pointers to find the answer
				4. Find the origin index
 */

#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> Index;
        vector<int> num = numbers;
        sort(num.begin(), num.end());
        int i=0, j=num.size()-1;
        
        while(i<j){
            int sum = num[i] + num[j];
            if(sum == target){
                for(int k=0; k<num.size() && Index.size()<2; k++){
                    if(numbers[k] == num[i])
                        Index.push_back(k+1);
                    else if(numbers[k] == num[j])
                        Index.push_back(k+1);
                }
                break;
            }
            else if(target - num[i] > num[j])
                i++;
            else
                j--;
        }
        return Index;
    }
};
