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
    ListNode *reverse(ListNode *head)
    {
        ListNode* newHead = NULL;
        while(head != NULL)
        {
            ListNode* next = head->next;    //next node preserve
            head->next = newHead;   //make link
            
            //move
            newHead = head;
            head = next;
        }
        return newHead;
    }
    
     bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head-> next == NULL)
        {
            return true;
        }//single node
        
        //find middle
        //reverse fro that end to last
        //move the pointer 1 step ahead and another one on head
        //traverse and compare 
        //if pointer reaches null -> True
        
        int flag = 0;
        ListNode *s,*f,*prev,*newHead,*other_half = NULL;
        s = f = newHead = head;
        while(f != NULL && f->next != NULL) ///middle
        {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        other_half = reverse(prev->next);
        
        while(other_half != NULL)
        {
            if(newHead->val != other_half->val)
            {
                return false;
            }            
            newHead = newHead->next;
            other_half = other_half->next;
        }
        return true;

    }
};