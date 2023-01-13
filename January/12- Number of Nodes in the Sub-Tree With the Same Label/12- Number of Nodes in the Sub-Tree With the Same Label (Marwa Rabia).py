# Author: Marwa Rabia 
from collections import defaultdict
from collections import deque
from typing import List

class Solution:


    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        
        """
    This function takes in 3 arguments:
    - n: an integer representing the number of nodes in the tree
    - edges: a list of lists containing the edges of the tree
    - labels: a string containing the labels of the nodes in the tree
    It returns a list of integers where ith element represents the number of subtrees with the same label as ith node.
    """
    
    # Create a dictionary to store the edges of the tree, where the keys are the nodes, and the values are the set of adjacent nodes
        adj = defaultdict(set)
        for edge in edges:
            adj[edge[0]].add(edge[1])
            adj[edge[1]].add(edge[0])
            
        # used to store the count of occurrences of each letter in the subtree rooted at each node.
        counts = [[0] * 26 for _ in range(n)]
        q = deque()
        for node in range(n):
            #Increment the count of the letter corresponding to the node in the `counts` list 

            counts[node][ord(labels[node]) - ord('a')] = 1
            #Check if the node is a leaf or not
            if node != 0 and len(adj[node]) == 1:
                #If it is a leaf then append it to the queue
                q.append(node)

        while q:
            curr = q.popleft()
            #Get the parent of the current node
            parent = next(iter(adj[curr]))
            #Remove the current node from the parent's adjacency list
            adj[parent].remove(curr)
            #Add the counts of the current node to its parent
            for i in range(26):
                counts[parent][i] += counts[curr][i]
            if parent != 0 and len(adj[parent]) == 1:
                q.append(parent)
        #Create a list to store the count of the label of the corresponding node from `counts` list
        ans = [0] * n
        for node in range(n):
            ans[node] = counts[node][ord(labels[node]) - ord('a')]

        return ans