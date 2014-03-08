/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode * temp = head;
        while(temp)
        {
            RandomListNode * copy = new RandomListNode(temp->label);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        temp = head;
        while(temp)
        {
            if(temp->random)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        RandomListNode * copy = head->next;
        temp = head;
        RandomListNode * first = copy;
        
        while(first)
        {
            temp->next = first->next;
            first->next = temp->next == NULL?NULL:temp->next->next;
            first = first->next;
            temp = temp->next;
        }
        return copy;
    }
};
