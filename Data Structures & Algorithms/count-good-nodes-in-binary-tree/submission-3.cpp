/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int result=0;
    void  help(TreeNode* root, int max)
    {
        if(root==nullptr)
            return;
        if(root->val>=max)
        {
            result+=1;
            help(root->left, root->val);
            help(root->right, root->val);
        }
        else
        {
            help(root->left, max);
            help(root->right, max);
        }

    }
    int goodNodes(TreeNode* root) 
    {
     help(root, INT_MIN);
     return result;
    }
};
