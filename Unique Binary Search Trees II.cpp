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
    vector<TreeNode *> generateTrees(int n) {
        if(n == 0)
            return generate(1, 0);
        return generate(1, n);
    }
    
    vector<TreeNode *> generate(int begin, int end)
    {
        vector<TreeNode *> vec;
        if(begin > end)
        {
            vec.push_back(NULL);
            return vec;
        }
        
        for(int i=begin;i<=end;i++)
        {
            vector<TreeNode *> leftNode = generate(begin, i-1);
            vector<TreeNode *> rightNode = generate(i+1, end);
            for(int x=0;x<leftNode.size();x++)
            {
                for(int y=0;y<rightNode.size();y++)
                {
                    TreeNode * root = new TreeNode(i);
                    root->left = leftNode[x];
                    root->right = rightNode[y];
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
};
