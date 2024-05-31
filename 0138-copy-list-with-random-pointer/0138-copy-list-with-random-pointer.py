"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
        def cloneInsert(self, head):
            ##step 1
            temp = head
            while temp is not None:
                copyNode = Node(temp.val)
                copyNode.next = temp.next
                temp.next = copyNode
                #move itr
                temp = temp.next.next
 
        def cloneRandomPointers(self, head):
            ##step 2
            temp = head
            while temp is not None:
                copyNode = temp.next  # start of cloned list
                if temp.random:
                    copyNode.random = temp.random.next
                # move itr
                temp = temp.next.next
        
        def segregateLinks(self, head):
            ##step 3
            dummyNode = Node(-1)
            res = dummyNode
            temp = head
            while temp is not None:
                res.next = temp.next  # start of cloned list
                # move itr
                temp.next = temp.next.next

                res = res.next
                temp = temp.next
            return dummyNode.next

        def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
            self.cloneInsert(head)
            self.cloneRandomPointers(head)
            return self.segregateLinks(head)
                
        