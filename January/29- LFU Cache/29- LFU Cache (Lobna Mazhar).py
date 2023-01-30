# Author: Lobna Mazhar

class Node:

    def __init__(self, key: int, value: int, counter: int):
        self.left, self.right, self.key, self.val, self.counter = None, None, key, value, counter

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.data = {}
        self.useCounter, self.minUsedCounter = defaultdict(list), 0
        self.start, self.end = Node(-1, -1, 0), Node(-1, -1, 0)
        self.start.right, self.end.left = self.end, self.start

    def get(self, key: int) -> int:
        if key in self.data:
            node = self.data[key]
            self.decrementCounter(node)
            self.incrementCounter(node)
            return node.val
        return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0: return
        
        if key in self.data:
            node = self.data[key]
            self.decrementCounter(node)
            self.incrementCounter(node)
            node.val = value
        else: 
            if len(self.data) == self.capacity:
                self.freeMemory()
                
            self.data[key] = self.insert(key, value, 0)

    def insert(self, key: int, value: int, counter: int) -> Node:
        node = Node(key, value, counter)
        prev, nxt = self.end.left, self.end
        node.left, node.right = prev, nxt
        prev.right, nxt.left = node, node
        self.incrementCounter(node)
        return node

    def remove(self, node: Node) -> None:
        prev, nxt = node.left, node.right
        prev.right, nxt.left = nxt, prev
    
    def incrementCounter(self, node):
        if self.minUsedCounter == 0 or node.counter < self.minUsedCounter:
            self.minUsedCounter = node.counter + 1
        node.counter += 1
        self.useCounter[node.counter].append(node)
    
    def decrementCounter(self, node):
        count = node.counter
        self.useCounter[count].remove(node)
        if len(self.useCounter[count]) == 0:
            if self.minUsedCounter == count: self.minUsedCounter = 0
            del self.useCounter[count]

    def freeMemory(self):
        lfu = self.useCounter[self.minUsedCounter][0]
        self.decrementCounter(lfu)
        del self.data[lfu.key]
        self.remove(lfu)

                        

        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)