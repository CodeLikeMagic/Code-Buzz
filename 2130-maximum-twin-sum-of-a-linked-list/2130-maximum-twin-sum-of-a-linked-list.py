# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        prev = None

        while(temp != None):
            front = temp.next
            temp.next = prev
            prev = temp
            temp = front

        return prev
    
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow , fast = head, head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
            
        listOne = head
        listTwo = self.reverse(slow)
        prev.next = None
        
        res = 0
        while listOne:
            res = max(res, listOne.val + listTwo.val)
            listOne = listOne.next
            listTwo = listTwo.next
        return res