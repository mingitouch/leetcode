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
    
    int minDepth(TreeNode *root) {
        return depth(root, false);
    }
    
    int depth(TreeNode * root, bool hasBrother)
    {
        if(!root)
            return hasBrother?INT_MAX:0;
        return 1 + min(depth(root->left, root->right != NULL), depth(root->right, root->left != NULL));
    }
};
