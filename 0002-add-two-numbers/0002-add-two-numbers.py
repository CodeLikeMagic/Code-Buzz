# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        temp1 = l1
        temp2 = l2
        #will point to resultant list
        dummyHead = ListNode(-1)
        #itr
        curr = dummyHead
        carry = 0
        acc = 0
        
        while(temp1 is not None or temp2 is not None):
            acc = carry
            if temp1:
                acc = acc + temp1.val
            if temp2:
                acc = acc + temp2.val
            
            newNode = ListNode(acc%10)
            carry = acc//10
            curr.next = newNode
            curr = curr.next

            if temp1:
                temp1 = temp1.next
            if temp2:
                temp2 = temp2.next

        if carry:
            newNode = ListNode(carry)
            curr.next = newNode

        return dummyHead.next