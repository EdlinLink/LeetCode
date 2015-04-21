/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 30, 2014
    Problem:    Binary Tree Zigzag Level Order Traversal 
    Source:     https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

    Given a binary tree, return the zigzag level order traversal of its nodes' values. 
    (ie, from left to right, then right to left for the next level and alternate between).

    For example:
    Given binary tree {3,9,20,#,#,15,7},

        3
       / \
      9  20
        /  \
       15   7

    return its level order traversal as:

    [
      [3],
      [20,9],
      [15,7]
    ]

    Definition for binary tree

        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    Solution:   Use two vector to record the level order iteratively

 */


class Solution {
public:
    vector<vector<int> > result;

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        result.clear();
        vector<TreeNode*> v_p;

        if(!root)   return result;
        v_p.push_back(root);
        level(v_p);

        return result;
    }

    void level(vector<TreeNode*> p){
        bool re = false;
        while(!p.empty()){
            vector<int> v;
            for(int i=0; i<p.size(); i++)
                v.push_back(p[i]->val);

            if(re)
                reverse(v.begin(), v.end());
            result.push_back(v);

            vector<TreeNode*> p2;

            for(int i=0; i<p.size(); i++){
                if(p[i]->left!=NULL)
                    p2.push_back(p[i]->left);
                if(p[i]->right!=NULL)
                    p2.push_back(p[i]->right);
            }
 
            p = p2;
            re = !re;
        }
    }
};
