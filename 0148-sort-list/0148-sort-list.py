# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge2Lists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        t1 = list1
        t2 = list2
        # head
        DummyNode = ListNode(-1)
        temp = DummyNode

        while (t1 != None and t2 != None):
            if t1.val < t2.val:
                temp.next = t1
                temp = t1
                t1 = t1.next
            else:
                temp.next = t2
                temp = t2
                t2 = t2.next
        if t1:
            temp.next = t1
        if t2:
            temp.next = t2
        return DummyNode.next

    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head.next    #skip on step so it reaches end early
        while (fast != None and fast.next != None):
            slow = slow.next
            fast = fast.next.next
        return slow

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        middle = self.middleNode(head)  #O(N/2)
        leftHead = head
        rightHead = middle.next
        middle.next = None
        leftHead = self.sortList(leftHead)
        rightHead = self.sortList(rightHead)
        return self.merge2Lists(leftHead, rightHead)    #O(N1 + N2)

#depth of fnct call will be logarithmic
#Tc : O(log N) * O(N1+N2 + N/2)
#Sc : O(N)  #recurive stack        