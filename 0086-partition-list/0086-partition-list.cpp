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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallerLL = new ListNode(0);
        ListNode* grtrLL = new ListNode(0);
        ListNode* sItr = smallerLL;
        ListNode* gItr = grtrLL;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
               sItr->next = head;
               sItr = sItr->next;
            }
            else
            {
               gItr->next = head;
               gItr = gItr->next;
            }
            head = head->next;
        }
        gItr->next = NULL;
        sItr->next = grtrLL->next;
        return smallerLL->next;
    }
};