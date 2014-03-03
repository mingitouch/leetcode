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
    vector<vector<int> > levelOrder(TreeNode *root) {
        int now=0;
        
        vector<vector<int> > res;
        if(root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> vec;
        while(!q.empty())
        {
            TreeNode * temp = q.front();
            q.pop();
            if(!temp)
            {
                res.push_back(vec);
                vec.clear();
                if(q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                vec.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};
