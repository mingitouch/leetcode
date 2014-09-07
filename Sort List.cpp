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
    ListNode *sortList(ListNode *head) {
        if(!head)
            return NULL;
        if(head and !head->next)
            return head;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode * l1 = sortList(head);
        ListNode * l2 = sortList(fast);
        return mergeList(l1, l2);
    }
    
    ListNode * mergeList(ListNode * l1, ListNode * l2)
    {
        ListNode * head = new ListNode(-1);
        ListNode * temp = head;
        while(l1 and l2)
        {
            if(l1->val < l2->val)
            {
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while(l1)
        {
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2)
        {
            temp->next = new ListNode(l2->val);
            l2 = l2->next;
            temp = temp->next;
        }
        return head->next;
    }
};
