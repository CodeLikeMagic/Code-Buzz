# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummyNode = ListNode(-1)
        dummyNode.next = head
        curr = dummyNode.next
        prev = dummyNode
        
        while curr:
            nxt = curr.next
            
            if curr.val == val:
                prev.next = nxt #skip that node    
            else:
                prev = curr
            curr = nxt
        return dummyNode.next
            