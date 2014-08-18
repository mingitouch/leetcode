/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * Head = new ListNode(0);
        Head->next = head;
        ListNode * old = Head;
        ListNode * now = head;
        while(now && now->next)
        {
            if(now->val == now->next->val)
            {
                while(now->next && now->val == now->next->val)
                {
                    now = now->next;
                }
                old->next = now->next;
                now = now->next;
            }
            else
            {
                old = now;
                now = now->next;
            }
        }
        head = Head->next;
        return head;
    }
};
