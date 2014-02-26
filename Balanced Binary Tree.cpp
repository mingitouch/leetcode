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
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        if(height(root->left)-height(root->right)<-1 || height(root->left)-height(root->right)>1)
            return false;
        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        return true;
    }
    
    int height(TreeNode * root)
    {
        if(root == NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
};
