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
    ListNode* kthnode(ListNode* curr, int k)
    {
        while(curr && k--)
        {
            curr = curr->next;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* groupprev = dummy;  // for first time this is the previous
        while(true)
        {
            ListNode* kth = kthnode(groupprev, k);   // we got our prev location
            if(!kth) break;    // kth node reaches outside

            ListNode* prev = kth->next;
            ListNode* curr = groupprev->next;   // curr stays on groupprev
            ListNode* groupNext = kth->next;

            while(curr!=groupNext)
            {
                ListNode* n = curr->next;
                curr->next = prev;
                prev = curr;
                curr = n;
            }
            ListNode* temp =groupprev->next;
            groupprev->next = kth;
            groupprev = temp;
        }
        return dummy->next;
    }
};
