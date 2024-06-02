# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyNode = ListNode(0)
        dummyNode.next = head

        prev = head
        curr = head.next
        while curr:
            if curr.val >= prev.val:
                prev = curr
                curr = curr.next
                continue
            #start from head to find correct pos for element
            tmp = dummyNode
            while curr.val > tmp.next.val:
                tmp = tmp.next
            #link
            prev.next = curr.next
            curr.next = tmp.next
            tmp.next = curr
            curr = prev.next
            
        return dummyNode.next