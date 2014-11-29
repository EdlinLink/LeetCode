/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Binary Tree Inorder Traversal
    Source:     https://oj.leetcode.com/problems/binary-tree-inorder-traversal/#

    Given a binary tree, return the inorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},
       1
        \
         2
        /
       3
    return [1,3,2].

    Note: Recursive solution is trivial, could you do it iteratively?

    confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

    OJ's Binary Tree Serialization:
    The serialization of a binary tree follows a level order traversal, 
    where '#' signifies a path terminator where no node exists below.

    Here's an example:
        1
       / \
      2   3
     /
    4
     \
      5
    The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

    Definition for binary tree
    
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };


    Solution:   1.  Push the father node into stack,   
                2.  Move to left node
                3.  If no left node
                4.  Get the top element in stack, move to right node
 */


class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *p = root;

        while(!s.empty() || p!=NULL){
            if(p!=NULL){
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }

        return result;
    }
};
