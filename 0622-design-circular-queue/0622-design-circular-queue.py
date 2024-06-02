class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
class MyCircularQueue:

    def __init__(self, k: int):
        self.cqSize = k
        self.left = Node()  #points to head
        self.right = Node() #points to tail
        self.left.next = self.right
        self.right.prev = self.left
        
    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        else:
            #adds at the end of queue using right
            newNode = Node(value)
            newNode.prev = self.right.prev
            newNode.next = self.right
            self.right.prev.next = newNode
            self.right.prev = newNode
            self.cqSize -= 1
            return True
        
    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        else:
            #removes at front of queue using left
            self.left.next = self.left.next.next
            self.left.next.prev = self.left
            self.cqSize += 1
            return True
        
    def Front(self) -> int:
        if self.isEmpty():
            return -1
        else:
            return self.left.next.val

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        else:
            return self.right.prev.val
            
    def isEmpty(self) -> bool:
        return self.left.next == self.right

    def isFull(self) -> bool:
        return self.cqSize == 0

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()