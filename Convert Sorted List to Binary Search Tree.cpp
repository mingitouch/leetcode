/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)
            return NULL;
        ListNode * tail = head;
        int high = 0;
        int low = 0;
        while(tail)
        {
            tail = tail->next;
            high++;
        }
        TreeNode * root;
        BST(root, head, low, high-1);
        //return BST(head, low, high-1);;
        return root;
    }
    
/*    TreeNode * BST(ListNode * & head, int low, int high)
    {
        if(low > high)
            return NULL;
        int mid = (low + high) / 2;
        TreeNode * leftNode = BST(head, low, mid - 1);
        TreeNode * root = new TreeNode(head->val);
        root->left = leftNode;
        head = head->next;
        root->right = BST(head, mid+1, high);
        return root;
    }*/
    void BST(TreeNode * & root, ListNode * & head, int low, int high)
    {
        if(low > high)
            return ;
        int mid = (low + high) / 2;
        root = new TreeNode(-1);
        BST(root->left, head, low, mid-1);
        root->val = head->val;
        head = head->next;
        BST(root->right, head, mid+1, high);
    }
};
