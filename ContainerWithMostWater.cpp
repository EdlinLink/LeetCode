/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 19, 2014
    Problem:    Container With Most Water  
    Source:     https://oj.leetcode.com/problems/container-with-most-water/
    Note:

    Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
    n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
    Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    Note: You may not slant the container.

    Solution:   Time complexity O(n).
                1. Select the line of the leftmost and rightmost to be initial line.
                2. Record the current area and change the shorter line to the line next to it.
                3. Comparing the new area, record the max area.
                4. Repeat step 2 and 3 until the select lines meet.

                More explanation can be found here: 
                https://oj.leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        int area = 0;
        int left = 0;
        int right = height.size()-1;

        int area_tmp;
        while(left < right){
            if(height[left] < height[right]){
                area_tmp = (right-left) * height[left];
                if(area_tmp > area)
                    area = area_tmp;
                left++;
            }
            else{
                area_tmp = (right-left) * height[right];
                if(area_tmp > area)
                    area = area_tmp;
                right--;
            }
        }

        return area;
    }
};
