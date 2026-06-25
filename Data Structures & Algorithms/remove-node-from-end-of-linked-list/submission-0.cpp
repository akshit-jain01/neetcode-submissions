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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        int pos = count-n;
        if(pos==0)
        {
            temp = head;
            head = head->next;
            delete(temp);

            return head;
        }
        ListNode* nextn = head;
        for(int i = 1;i<pos;i++)
        {
            nextn = nextn->next;
        }
        ListNode* del = nextn->next;
        nextn->next = nextn->next->next;
        delete(del);
        return head;
    }
};
