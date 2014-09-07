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
    void reorderList(ListNode *head) {
        if(!head)
            return ;
        if(head and !head->next)
            return ;
        
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * pre = slow;
        while(fast and fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        pre->next = NULL;
        slow = reverse(slow);
        
        ListNode * now = head;
        while(now->next)
        {
            ListNode * temp = now->next;
            now->next = slow;
            slow = slow->next;
            now->next->next = temp;
            now = temp;
        }
        now->next = slow;
    }
    
    ListNode * reverse(ListNode * list)
    {
        if(!list)
            return NULL;
        if(list and !list->next)
            return list;
        ListNode * now = list;
        ListNode * then = list->next;
        now->next = NULL;
        while(true)
        {
            ListNode * temp = then->next;
            then->next = now;
            now = then;
            if(!temp)
                break;
            then = temp;
        }
        return then;
    }
};
