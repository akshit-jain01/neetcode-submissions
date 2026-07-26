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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while(h1 && h2)
        {
            if(h1->val<=h2->val)
            {
                tail->next = h1;
                h1 = h1->next;
            }
            else
            {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        if(h1)
        {
            tail->next = h1;
        }
        else
        {
            tail->next = h2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        if(lists.empty())
        {
            return NULL;
        }
        int i;
        for(i=1;i<lists.size();i++)
        {

            lists[i] = mergeTwoLists(lists[i], lists[i-1]);
        }

        return lists[i-1];
    }
};
