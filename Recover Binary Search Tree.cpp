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
    TreeNode * s1;
    TreeNode * s2;
    TreeNode * pre;
    void recoverTree(TreeNode *root) {
        s1 = NULL;
        s2 = NULL;
        pre = NULL;
        find(root);
        swap(s1->val, s2->val);
    }
    
    void find(TreeNode * root)
    {
        if(!root)
            return ;
        find(root->left);
        if(pre and pre->val > root->val)
        {
            if(!s1)
            {
                s1 = pre;
                s2 = root;
            }
            else
            {
                s2 = root;
            }
        }
        pre = root;
        find(root->right);
    }
};
