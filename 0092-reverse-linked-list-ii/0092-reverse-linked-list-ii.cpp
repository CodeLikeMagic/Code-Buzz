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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next == NULL) return head;
        
        int K = right-left+1;
        ListNode* prev, *curr;
        curr = head;
        int i=0;
        if(left == 1)
        {
            prev = curr;
        }
        else
        {
            while(i < left-1)
            {
                prev = curr;
                curr = curr->next;
                i++;
            }    
        }

        i = 0;

        ListNode* old_curr = curr;
        ListNode* newHead = NULL;
        while(i < K)
        {
            ListNode* next = curr->next;    //preserve
            curr->next = newHead;   //make link

            newHead = curr;
            curr = next;
            i++;
        }
        if(left != 1)
            prev->next = newHead;
        if(left == 1)
            head = newHead;
        if(old_curr)
            old_curr->next = curr;
        return head;
    }
};
