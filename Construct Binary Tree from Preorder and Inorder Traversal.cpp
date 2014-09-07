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
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode * build(vector<int> & preorder, int begin_one, int end_one, vector<int> & inorder, int begin_two, int end_two)
    {
        if(begin_one > end_one or begin_two > end_two)
            return NULL;
        
        int mid;
        TreeNode * root = new TreeNode(preorder[begin_one]);
        for(int i=begin_two;i<=end_two;i++)
        {
            if(inorder[i] == preorder[begin_one])
            {
                mid = i;
                break;
            }
        }
        
        root->left = build(preorder, begin_one+1, begin_one+mid-begin_two, inorder, begin_two, mid-1);
        root->right = build(preorder, begin_one+mid-begin_two+1, end_one, inorder, mid+1, end_two);
        return root;
    }
};
