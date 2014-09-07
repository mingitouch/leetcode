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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode * build(vector<int> & inorder, int begin_one, int end_one, vector<int> & postorder, int begin_two, int end_two)
    {
        if(begin_one > end_one or begin_two > end_two)
            return NULL;
        TreeNode * root = new TreeNode(postorder[end_two]);
        int mid;
        for(int i=begin_one;i<=end_one;i++)
        {
            if(inorder[i] == postorder[end_two])
            {
                mid = i;
                break;
            }
        }
        root->left = build(inorder, begin_one, mid-1, postorder, begin_two, begin_two+mid-begin_one-1);
        root->right = build(inorder, mid+1, end_one, postorder, begin_two+mid-begin_one, end_two-1);
        return root;
    }
};
