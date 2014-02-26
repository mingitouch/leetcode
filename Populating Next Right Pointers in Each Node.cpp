/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        root->next = NULL;
        link(root->left, root->right);
    }
    
    void link(TreeLinkNode * Left, TreeLinkNode * Right)
    {
        if(Left && Right)
        {
            Left->next = Right;
            link(Left->right, Right->left);
            link(Left->left, Left->right);
            link(Right->left, Right->right);
        }
        else if(Left)
        {
            link(Left->left, Left->right);
        }
        else if(Right)
        {
            link(Right->left, Right->right);
        }
    }
};
