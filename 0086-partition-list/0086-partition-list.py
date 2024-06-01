# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        leftNode = ListNode()
        rightNode = ListNode()
        litr = leftNode
        ritr = rightNode
        temp = head
        
        while temp:
            if temp.val < x:
                litr.next = temp
                litr = litr.next
            else:
                ritr.next = temp
                ritr = ritr.next
            temp = temp.next
            
        #link first node with second node's head
        litr.next = rightNode.next
        #make second node tail as null
        ritr.next = None
        return leftNode.next