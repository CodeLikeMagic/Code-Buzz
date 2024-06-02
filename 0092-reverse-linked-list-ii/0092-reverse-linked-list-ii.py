# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        #node before reversal
        leftPrev = dummy
        curr = head
        for i in range(left - 1):
            leftPrev = curr
            curr = curr.next

        #curr holds leftmost node of range
        #curr = left, leftPrev = node before left
        prev = None
        for i in range(right - left + 1):
            tempNext = curr.next
            curr.next = prev
            prev = curr         #4
            curr = tempNext     #5

        #update pointers
        leftPrev.next.next = curr           #cur is node after "right"
        leftPrev.next = prev                #prev is "right"
        return dummy.next
