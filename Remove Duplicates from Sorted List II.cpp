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
        unordered_map<int, int> mp;
        ListNode * temp = head;
        if(head == NULL)
            return NULL;
        while(temp)
        {
            if(!mp.count(temp->val))
                mp[temp->val] = 1;
            else mp[temp->val]++;
            temp = temp->next;
        }
        temp = head;
        ListNode * last = temp;
        while(temp)
        {
            if(mp[temp->val] > 1)
            {
                if(temp == head)
                {
                    temp = temp->next;
                    head = temp;
                    last = temp;
                }
                else
                {
                    last->next = temp->next;
                    temp = last->next;
                }
            }
            else
            {
                if(temp == head)
                {
                    temp = temp->next;
                }
                else
                {
                    last = temp;
                    temp = temp->next;
                }
            }
        }
        return head;
    }
};
