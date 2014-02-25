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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int flag = 0;
        ListNode * head = new ListNode(0);
        ListNode * tail = head;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL && l2 != NULL)
            {
                int val = l1->val + l2->val + flag;
                if(val>=10)
                {
                    val = val % 10;
                    flag = 1;
                }
                else
                    flag = 0;
                tail->next = new ListNode(val);
                tail = tail->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l2 != NULL)
            {
                int val = l2->val + flag;
                if(val >= 10)
                {
                    val = val % 10;
                    flag = 1;
                }
                else
                    flag = 0;
                tail->next = new ListNode(val);
                tail = tail->next;
                l2 = l2->next;
            }
            else if(l1 != NULL)
            {
                int val = l1->val + flag;
                if(val >= 10)
                {
                    val = val % 10;
                    flag = 1;
                }
                else
                    flag = 0;
                tail->next = new ListNode(val);
                tail = tail->next;
                l1 = l1->next;
            }
            
        }
        if(l1 == NULL && l2 == NULL)
        {
            if(flag == 1)
            {
                tail->next = new ListNode(1);
            }
        }
        return head->next;
    }
};
