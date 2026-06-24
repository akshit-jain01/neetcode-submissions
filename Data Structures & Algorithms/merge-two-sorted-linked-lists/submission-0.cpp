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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *temp, *temp1, *temp2;
        head = new ListNode();
        temp = head;
        temp1 = list1;
        temp2 = list2;
        while(temp1 && temp2)
        {
            if(temp1->val<=temp2->val)
            {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
                temp->next = NULL;
            }
            else
            {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
                temp->next = NULL;
            }
        }
        if(temp1==NULL)
        {
            temp->next = temp2;
        }
        else if(temp2==NULL)
        {
            temp->next = temp1;
        }
        
        return head->next;

    }
};
