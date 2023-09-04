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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
        {
            return false;
        }   //if there's a single node
        
        ListNode* f, *s;
        f = s = head;
        
        while(f->next && f->next->next) //if next or next->next is NULL that means there's no cycle exit
        {
            f = f->next->next;  
            s = s->next;
            
            if(f == s)
            {
                return true;
            }
        }
        return false;
    }
};