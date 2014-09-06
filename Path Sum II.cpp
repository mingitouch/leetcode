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
    vector<vector<int> > vec;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(!root)
            return vec;
        vector<int> path;
        dfs(root, path, sum);
        return vec;
    }
    
    void dfs(TreeNode * root, vector<int> path, int sum)
    {
        if(!root)
            return ;
        if(!root->left and !root->right)
        {
            if(root->val == sum)
            {
                path.push_back(root->val);
                vec.push_back(path);
                return ;
            }
            else
                return ;
        }
        path.push_back(root->val);
        dfs(root->left, path, sum-root->val);
        path.pop_back();
        path.push_back(root->val);
        dfs(root->right, path, sum-root->val);
        path.pop_back();
    }
};
