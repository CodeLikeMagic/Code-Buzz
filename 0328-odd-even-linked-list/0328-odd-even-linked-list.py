# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        
        oddItr = head
        evenItr = head.next
        evenHead = head.next
        
        while(evenItr != None and evenItr.next != None):
            
            oddItr.next = oddItr.next.next
            evenItr.next = evenItr.next.next
            oddItr = oddItr.next
            evenItr = evenItr.next
            
        
        oddItr.next = evenHead
        return head