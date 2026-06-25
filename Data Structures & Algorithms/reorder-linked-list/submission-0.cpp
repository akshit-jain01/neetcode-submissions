/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode* slow, *fast;
        slow = head;
        fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }   // slow is on the middle node, next reverse form the slow node
        ListNode* prev = NULL;
        ListNode* cur = slow->next;
        ListNode* next;
        slow->next = NULL;
        
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        ListNode* temp1 = head;
        ListNode* temp2;
        ListNode* change;
        while(prev)
        {
            temp2 = temp1->next;
            change = prev->next;
            temp1->next = prev;
            prev->next = temp2;
            prev = change;
            temp1 = temp2;
        }
    }
};
