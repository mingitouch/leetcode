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
    bool isValidBST(TreeNode *root) {
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        else if(root->left && root->right == NULL)
        {
            return (maxNode(root->left)<root->val) && isValidBST(root->left);
        }
        else if(root->left == NULL && root->right)
        {
            return (minNode(root->right)>root->val) && isValidBST(root->right);
        }
        else
            return (maxNode(root->left)<root->val && minNode(root->right)>root->val) && isValidBST(root->left) && isValidBST(root->right);
    }
    
    int maxNode(TreeNode * root)
    {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        else if(root->left && root->right == NULL)
        {
            return max(root->val,root->left->val);
        }
        else if(root->right && root->left == NULL)
        {
            return max(root->val,root->right->val);
        }
        else
            return max(maxNode(root->left), maxNode(root->right));
    }
    int minNode(TreeNode * root)
    {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        else if(root->left && root->right == NULL)
        {
            return min(root->val,root->left->val);
        }
        else if(root->right && root->left == NULL)
        {
            return min(root->val,root->right->val);
        }
        else
            return min(minNode(root->left), minNode(root->right));
    }
};
