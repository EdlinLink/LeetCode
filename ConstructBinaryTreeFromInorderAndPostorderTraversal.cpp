/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Apr. 21, 2015
    Problem:    Construct Binary Tree from Inorder and Postorder Traversal
    Source:     https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
    ----------------------------------------------------------------------------------------------------
    Given inorder and postorder traversal of a tree, construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.
    ----------------------------------------------------------------------------------------------------
    Solution:   1.  Map postorder num position in inorder: postorder[i] = inorder[pos[i]].
                2.  The last element of preorder will splite the inorder into 2 parts, left/right tree.
                3.  Recursive splite the inorder into 2 parts until no more split.
 */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        vector<int> pos;
        for(int i=0; i<postorder.size(); i++){
            for(int j=0; j<inorder.size(); j++){
                if(postorder[i]==inorder[j]){
                    pos.push_back(j);
                    break;
                }
            }
        }
        
        TreeNode *root = createTree(inorder, postorder, pos, postorder.size()-1, 0, postorder.size());
        return root;
    }


    TreeNode *createTree(vector<int> &inorder, vector<int> &postorder, vector<int> &pos, int index, int start, int end){
        if(start>=end)  return NULL;

        TreeNode *p = new TreeNode(postorder[index]);
        p->right = createTree(inorder, postorder, pos, index-1, pos[index]+1, end);
        p->left = createTree(inorder, postorder, pos, index-1 - (end-(pos[index]+1)), start, pos[index]);

        return p;
    }
};
