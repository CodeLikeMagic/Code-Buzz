# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
"""
identify len of list
recalc K 
make circular list
K - len steps
manipulate links
"""

class Solution:
    def findNthNode(self, head, k):
        step = 1
        while(head is not None):
            if step == k:
                return head
            head = head.next
            step += 1
        return head
        
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or k == 0:
            return head
        tail = head
        list_len = 1
        while tail.next != None:
            tail = tail.next
            list_len += 1
        
        if (k%list_len == 0):
            return head
        
        k = k%list_len
            
        #made it circular list
        tail.next = head
        
        newLastNode = self.findNthNode(head, list_len-k)
        head = newLastNode.next
        newLastNode.next = None
        
        return head