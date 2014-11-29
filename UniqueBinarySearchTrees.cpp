/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Unique Binary Search Trees 
    Source:     https://oj.leetcode.com/problems/unique-binary-search-trees/

    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

    For example,
    Given n = 3, there are a total of 5 unique BST's.

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3


    Solution:   Ways of a father node: W(father_node) = W(left_node)*W(right_node)
 */


class Solution {
public:
    int numTrees(int n) {
        return way(1, n);
    }


    int way(int a, int b){
        if(a > b)    
            return 1;
        else{
            int total = 0;
            for(int i=a; i<=b; i++)
                total += way(a, i-1) * way(i+1, b);
            return total;
        }
    }
};
