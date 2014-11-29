/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Unique Binary Search Trees II
    Source:     https://oj.leetcode.com/problems/unique-binary-search-trees-ii/

    Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

    For example,
    Given n = 3, there are a total of 5 unique BST's.

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3


    Definition for binary tree

        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    Solution:   Similar to problem `Unique Binary Search Trees`.
                The different is that return the `pointer` not the `num of way`.
 */


class Solution {
public:


    vector<TreeNode *> generateTrees(int n) {
        return way(1, n);
    }

    vector<TreeNode *> way(const int& a, const int& b){
        vector<TreeNode *> result;
        if(a > b) {
            result.push_back(NULL);
            return result;
        }
        else{
            for(int k=a; k<=b; k++){
                vector<TreeNode *> v_left = way(a, k-1);
                vector<TreeNode *> v_right = way(k+1, b);

                for(int i=0; i<v_left.size(); i++){
                    for(int j=0; j<v_right.size(); j++){
                        TreeNode *node = new TreeNode(k);
                        node->left = v_left[i];
                        node->right = v_right[j];
                        result.push_back(node);
                    }
                }
            }
            return result;
        }
    }
};
