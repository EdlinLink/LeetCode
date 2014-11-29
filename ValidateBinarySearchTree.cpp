/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Validate Binary Search Tree 
    Source:     https://oj.leetcode.com/problems/validate-binary-search-tree/

    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

    Definition for binary tree

        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    Solution:   Recursive to check validation

 */


class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return valid(root, INT_MIN, INT_MAX);
    }

    bool valid(TreeNode *p, double min, double max){
        if(p==NULL) return true;
        if(p->val < min || p->val > max)  return false;
        return valid(p->left, min, double(p->val)-1) && valid(p->right, double(p->val)+1, max);
    }
};
