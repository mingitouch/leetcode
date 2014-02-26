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
        TreeLinkNode * left = root->left;
        TreeLinkNode * right = root->right;
        if(left)
        {
            if(right)
            {
                left->next = right;
                TreeLinkNode * temp = root->next;
                while(temp)
                {
                    if(temp->left || temp->right)
                    {
                        break;
                    }
                    temp = temp->next;
                }
                if(temp)
                {
                    if(temp->left)
                        right->next = temp->left;
                    else
                        right->next = temp->right;
                }
            }
            else
            {
                TreeLinkNode * temp = root->next;
                while(temp)
                {
                    if(temp->left || temp->right)
                    {
                        break;
                    }
                    temp = temp->next;
                }
                if(temp)
                {
                    if(temp->left)
                        left->next = temp->left;
                    else
                        left->next = temp->right;
                }
            }
        }
        else if(right)
        {
            TreeLinkNode * temp = root->next;
            while(temp)
            {
                if(temp->left || temp->right)
                {
                    break;
                }
                temp = temp->next;
            }
            if(temp)
            {
                if(temp->left)
                    right->next = temp->left;
                else
                    right->next = temp->right;
            }
        }
        connect(root->right);
        connect(root->left);
    }
    
};
