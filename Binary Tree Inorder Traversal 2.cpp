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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
        TreeNode * curr = root;
        stack<TreeNode *> s;
        //s.push(curr);
        while(curr || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            if(!s.empty())
            {
                curr = s.top();
                s.pop();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        return result;
    }
};
