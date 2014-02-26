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
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode * node = s.top();
            s.pop();

            if(node->left == NULL && node->right == NULL)
            {
                result.push_back(node->val);
                while(!s.empty() && s.top()->right == NULL)
                {
                    result.push_back(s.top()->val);
                    s.pop();
                }
                if(!s.empty())
                {
                    result.push_back(s.top()->val);
                    s.pop();
                }
            }
            else if(node->left && node->right == NULL)
            {
                s.push(node);
                s.push(node->left);
            }
            else if(node->left == NULL && node->right)
            {
                result.push_back(node->val);
                s.push(node->right);
            }
            else if(node->left && node->right)
            {
                s.push(node->right);
                s.push(node);
                s.push(node->left);
            }
        }
        return result;
    }
};
