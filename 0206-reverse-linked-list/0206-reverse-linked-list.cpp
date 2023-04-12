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
    ListNode* newHead;
    ListNode* reverseHelp(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        if(head->next == NULL)
        {
            newHead = head;
            return head;
        }
        
        ListNode *node1 = reverseHelp(head->next);
        
        node1->next = head;
        head->next = NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *node = reverseHelp(head);
        if(node)
        {
            node->next = NULL; //first Node    
        }
        head = newHead;
        return head; ///new Head
    }
};