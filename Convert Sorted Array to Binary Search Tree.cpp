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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode * root = NULL;
        BST(root, num, 0, num.size()-1);
        return root;
    }
    
    void BST(TreeNode * & root, vector<int> & num, int low, int high)
    {
        if(low > high)
            return ;
        int mid = (low + high) / 2;
        if(!root)
        {
            root = new TreeNode(num[mid]);
        }
        BST(root->left, num, low, mid-1);
        BST(root->right, num, mid+1, high);
    }
};
