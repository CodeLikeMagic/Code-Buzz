/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         Node* curr, *next = NULL;
        curr = head;
        
        while(curr != NULL)
        {
            next = curr->next;  //preserve next
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next; //link new nodes next with latter node
            curr->next = newNode;   //link it with new 
            curr = next;    //move
        }
        
        //linking on random pointers
        for(curr = head; curr != NULL;curr = curr->next->next)
        {
            //newNode random
            curr->next->random = (curr->random != NULL)?curr->random->next:NULL;
        }
        
        //separating both lists and relinking each of there nodes in respective list
        curr = head;
        Node* copy;
        Node* psuedoHead = new Node(0);
        copy = psuedoHead;  ///deep copy list
        
        while(curr != NULL)
        {
            
            next = curr->next->next;    //preserve next of original
            
            copy->next = curr->next;    //deep copy linking and its separation
            
            curr->next = next; //orignal's next
            
            //move
            copy = copy->next;
            curr = next;
        }
        
        return psuedoHead->next;
    }
};