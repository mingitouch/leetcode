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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int> >result;
        vector<int> lev;
        if(root == NULL)
        {
            return result;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode * temp = q.front();
            q.pop();
            if(temp == NULL)
            {
//                reverse(lev.begin(), lev.end())
                result.push_back(lev);
                lev.clear();
                if(q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                lev.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
