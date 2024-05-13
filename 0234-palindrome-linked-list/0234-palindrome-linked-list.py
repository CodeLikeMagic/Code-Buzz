# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        prev = None

        while(temp != None):
            front = temp.next
            temp.next = prev
            prev = temp
            temp = front

        return prev
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        #for single node
        if head is None or head.next is None:
            return True
        
        #find mid of LL
        slow = head
        fast = head
        firstHalf = head
        while (fast != None and fast.next != None):
            slow = slow.next
            fast = fast.next.next
        #reverse other half
        secondHalf = self.reverseList(slow)
        
        while secondHalf is not None:
            if firstHalf.val != secondHalf.val:
                return False
            firstHalf = firstHalf.next
            secondHalf = secondHalf.next
        return True    
        