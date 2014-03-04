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
        if(num.size() == 0)
            return NULL;
        TreeNode * root;
        int begin = 0;
        int end = num.size()-1;
        root = new TreeNode(num[(begin+end)/2]);
        create(root, num, begin, end);
        return root;
    }
    
    void create(TreeNode * &root, vector<int> & num, int low, int high)
    {
        int mid = (low+high)/2;
        if(low == high)
        {
            root = new TreeNode(num[mid]);
            return;
        }
        if(low > high)
            return;
        root = new TreeNode(num[mid]);
        create(root->left, num, low, mid-1);
        create(root->right, num, mid+1, high);
    }
};
