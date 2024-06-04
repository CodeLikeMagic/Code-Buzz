# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
       def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length, curr = 0, head
        while curr:
            curr = curr.next
            length += 1

        base_len, remainder = length // k, length % k

        curr = head
        res = []
        #default partition size is 1
        for i in range(k):
            res.append(curr)
            for j in range(base_len - 1 + (1 if remainder else 0)): #links nodes for a part
                #print("here")
                if not curr:
                    break
                curr = curr.next
            remainder -= (1 if remainder else 0)
            #print(remainder)
            if curr:
                curr.next, curr = None, curr.next
        return res