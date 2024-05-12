class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.cnt = 1
        self.prev = None
        self.next = None
        
        
class List:
    def __init__(self):
        self.size = 0
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def addFront(self, node):
        temp = self.head.next
        node.next = temp
        node.prev = self.head
        self.head.next = node
        temp.prev = node
        self.size += 1
        
    def removeLast(self, delNode):
        prev = delNode.prev
        nxt = delNode.next
        prev.next = nxt 
        nxt.prev = prev
        self.size -= 1
        
        
class LFUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.minFreq = 0    #to evict LRU element
        self.curSize = 0
        self.keyNode = {}
        self.freqListMap = {}

    
    def updateFreqListMap(self, node):
        del self.keyNode[node.key]  
        #remove key from older freq list
        self.freqListMap[node.cnt].removeLast(node)
        
        if node.cnt == self.minFreq and self.freqListMap[node.cnt].size == 0:
            self.minFreq += 1
            
        nextFreqLevel = List()
        if node.cnt + 1 in self.freqListMap:
            nextFreqLevel = self.freqListMap[node.cnt + 1]
        
        node.cnt += 1
        nextFreqLevel.addFront(node)
        self.freqListMap[node.cnt] = nextFreqLevel
        self.keyNode[node.key] = node
        
    def get(self, key: int) -> int:
        if key in self.keyNode:
            node = self.keyNode[key]    #fetch
            val = node.val
            self.updateFreqListMap(node)    ##########
            return val
        return -1

    def put(self, key: int, value: int) -> None:
        if self.cap == 0:
            return
        if key in self.keyNode:
            node = self.keyNode[key]    #fetch
            node.val = value          #update with new value
            self.updateFreqListMap(node)    ##########
        else:   #new key
            if self.curSize == self.cap:    #evict LRU element
                listToRemoveEleFr = self.freqListMap[self.minFreq]  
                del self.keyNode[listToRemoveEleFr.tail.prev.key]  #evict from KeyNode, tail element of list
                listToRemoveEleFr.removeLast(listToRemoveEleFr.tail.prev) #remove last element from the DLL
                self.curSize -= 1
                
            self.curSize += 1
            self.minFreq = 1    #freq for new element is 1
            listFreq = List()
            #if list with the given frequency already exists then add at front of that list
            if self.minFreq in self.freqListMap:
                listFreq = self.freqListMap[self.minFreq]
            
            node = Node(key, value)
            listFreq.addFront(node)
            self.keyNode[key] = node
            self.freqListMap[self.minFreq] = listFreq
            
            
            
            
            

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)