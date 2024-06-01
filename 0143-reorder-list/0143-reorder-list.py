# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def findMiddle(self, head):
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
    
    def reverse(self, head):
        curr = head
        prev = None
        while curr:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        return prev
    
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        middle = self.findMiddle(head)
        secondList = self.reverse(middle.next)
        middle.next = None
        firstList = head
        dummyNode = ListNode(-1)
        res = dummyNode
        
        while firstList or secondList:
            if firstList:
                res.next = firstList
                firstList = firstList.next
                res = res.next
            if secondList:
                res.next = secondList
                secondList = secondList.next
                res = res.next
        return dummyNode.next