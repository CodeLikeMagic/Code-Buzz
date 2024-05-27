# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution:
    """
    Tc : heappush/pop - log N, 
    TC : K * log K (initial insertion) + K * N * log K
    sc : O(K)
    """
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        #head 
        DummyNode = ListNode(-1)
        min_hp = []
        count = 0   #for comparator - to maintain order 
        temp = DummyNode
        #zeroth nodes from all lists
        # K * log K
        for li in lists:
            #print(li.val)
            #print(type(li))
            if li:
                count += 1
                heapq.heappush(min_hp, (li.val, count, li))
        # K * N * log K
        while len(min_hp) != 0:
            #fetch min element
            val, _, Node = heapq.heappop(min_hp)
            temp.next = Node
            if Node.next:
                count += 1
                heapq.heappush(min_hp, (Node.next.val, count, Node.next))
            temp = temp.next
        return DummyNode.next