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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;

        ListNode * fast = head;
        ListNode * slow = head;
        while(true)
        {
            if(fast->next == NULL)
                return NULL;
            if(fast->next->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        
    }
};
