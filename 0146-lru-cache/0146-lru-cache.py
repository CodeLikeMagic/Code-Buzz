class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
        
        #dummy nodes doubly linkedlist 
        #tail - LRU - back of DLL, head - most recent - front of DLL
        self.head, self.tail = Node(0, 0), Node(0, 0)    
        self.head.next = self.tail
        self.tail.prev = self.head
    
    #add node at front of DLL
    def add_node(self, node):
        node.prev = self.head
        node.next = self.head.next
        node.next.prev = node
        self.head.next = node
        
    #remove node from end of DLL
    def remove_node(self, node):
        prev, nxt = node.prev, node.next
        prev.next = nxt
        nxt.prev = prev
    
    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove_node(self.cache[key])
            #update node at front of DLL
            self.add_node(self.cache[key])            
            return self.cache[key].val
        #if key not present
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove_node(self.cache[key])
        #update node at front of DLL
        self.cache[key] = Node(key, value)
        self.add_node(self.cache[key])            

        if len(self.cache) > int(self.cap):
            #print("here")
            lru = self.tail.prev
            self.remove_node(lru)
            del self.cache[lru.key]
            
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)