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
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        maxSum(root, result);
        return result;
    }
    
    int maxSum(TreeNode * root, int & result)
    {
        if(!root)
            return 0;
        int leftMax = maxSum(root->left, result);
        int rightMax = maxSum(root->right, result);
        int across = leftMax + rightMax + root->val;
        int onePath = max(root->val, max(leftMax, rightMax)+root->val);
        result = max(result, max(across, onePath));
        return onePath;
    }
};
