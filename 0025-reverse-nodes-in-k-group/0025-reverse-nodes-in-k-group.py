# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head):
        curr = head
        prev = None
            
        while curr != None:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        return prev
    
    def findKthNode(self, temp, k):
        k -= 1
        while temp is not None and k>0 :
            temp = temp.next
            k -= 1
        return temp
        
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        temp = head
        nexNode = prevNode = None
        
        while temp is not None:
            kThNode = self.findKthNode(temp, k)
            if kThNode is None:
              if prevNode:
                prevNode.next = temp
                break
            
            #links of kth node
            nextNode = kThNode.next 
            kThNode.next = None
            #splitted
            
            self.reverse(temp)
            
            if temp == head:
                head = kThNode
            else:
                prevNode.next = kThNode
                
            prevNode = temp
            temp = nextNode
        return head                     
                
                
                
                
                
                
                
            