/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 30, 2014
    Problem:    Maximum Depth of Binary Tree 
    Source:     https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

    Given a binary tree, find its maximum depth.
    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Definition for binary tree

        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    Solution:   Traversal by level

 */


class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root)   return 0;

        vector<TreeNode *> v;
        v.push_back(root);
        int depth = 0;

        while(!v.empty()){
            depth++;
            vector<TreeNode *> v2;
            for(int i=0; i<v.size(); i++){
                if(v[i]->left != NULL)
                    v2.push_back(v[i]->left);
                if(v[i]->right != NULL)
                    v2.push_back(v[i]->right);
            }
            v = v2;
        }

        return depth;
    }
};

