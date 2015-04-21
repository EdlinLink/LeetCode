/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 30, 2014
    Problem:    Symmetric Tree
    Source:     https://oj.leetcode.com/problems/symmetric-tree/

    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

    For example, this binary tree is symmetric:

        1
       / \
      2   2
     / \ / \
    3  4 4  3
              
    But the following is not:
                 
        1
       / \
      2   2
       \   \
        3   3

    Definition for binary tree

        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

    Solution:   Use two vector to record preorder including the NULL

 */


class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        
        vector<TreeNode *> v1;
        vector<TreeNode *> v2;
        if(root==NULL)  
            return true;
        else if(root->left==NULL && root->right==NULL)
            return true;
        else if(root->left!=NULL && root->right!=NULL){
            Preorder_left(v1, root->left);
            Preorder_right(v2, root->right);
            if(v1.size()!=v2.size())
                return false;
            else{
                for(int i=0; i<v1.size(); i++)
                    if(v1[i] && v2[i] && v1[i]->val != v2[i]->val)
                        return false;
                    else if((v1[i] && !v2[i]) || (!v1[i] && v2[i]))
                        return false;
            }
            return true;
        }
        return false;
    }

    void Preorder_left(vector<TreeNode *>& v, TreeNode *p){
        if(p==NULL)
            v.push_back(p);
        else{
            v.push_back(p);
            Preorder_left(v, p->left);
            Preorder_left(v, p->right);
        }
    }

    void Preorder_right(vector<TreeNode *>& v, TreeNode *p){
        if(p==NULL)
            v.push_back(p);
        else{
            v.push_back(p);
            Preorder_right(v, p->right);
            Preorder_right(v, p->left);
        }
    }
};
