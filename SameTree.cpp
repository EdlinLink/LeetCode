/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 30, 2014
    Problem:    Same Tree 
    Source:     https://oj.leetcode.com/problems/same-tree/

    Given two binary trees, write a function to check if they are equal or not.
    Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    Solution:   Recursive traversal.

 */


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL && q==NULL)
            return true;
        else if(p!=NULL && q!=NULL)
            return (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right,q->right));
        else
            return false;
    }
};
