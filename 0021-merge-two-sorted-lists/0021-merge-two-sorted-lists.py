# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    #Tc : O(N1 + N2)    Sc: O(1)
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        t1 = list1
        t2 = list2
        #head
        DummyNode = ListNode(-1)
        temp = DummyNode
        
        while(t1 != None and t2 != None):
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