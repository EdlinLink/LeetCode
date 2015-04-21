/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Apr. 21, 2015
    Problem:    Construct Binary Tree from Preorder and Inorder Traversal 
    Source:     https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    ----------------------------------------------------------------------------------------------------
    Given preorder and inorder traversal of a tree, construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.
    ----------------------------------------------------------------------------------------------------
    Solution:   1.  Map preorder num position in inorder: preorder[i] = inorder[pos[i]].
                2.  The first element of preorder will splite the inorder into 2 parts, left/right tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        vector<int> pos;
        for(int i=0; i<preorder.size(); i++){
            for(int j=0; j<inorder.size(); j++){
                if(preorder[i]==inorder[j]){
                    pos.push_back(j);
                    break;
                }
            }
        }


        TreeNode* root = NULL;
        root = createTree(preorder, inorder, pos, 0, 0, preorder.size());           

        return root;
    }


    TreeNode* createTree(vector<int> &preorder, vector<int> &inorder, vector<int> &pos, int index, int start, int end){
        if(start>=end)  return NULL;

        TreeNode* p = new TreeNode(preorder[index]);
        p->left = createTree(preorder, inorder, pos, index+1, start, pos[index]);
        p->right = createTree(preorder, inorder, pos, index+1 + pos[index]-start, pos[index]+1, end);

        /************************************************************
         *  index+1 + pos[index-start]:                             *
         *      The new index position equals to                    *
         *      1. previous 'index' +                               *
         *      2. skip all left tree node 'pos[index]-start' +     *
         *      3. next one element                                 *
         ************************************************************/

        return p;
    }

};
