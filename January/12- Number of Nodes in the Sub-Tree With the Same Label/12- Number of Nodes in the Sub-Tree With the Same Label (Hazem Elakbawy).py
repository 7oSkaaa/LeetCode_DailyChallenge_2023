# Author : Hazem Elakbawy
class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        adj=[[] for _ in range(n)]
        # create an adjacency list
        for a,b in edges:
            # adding vertices in both directions (undirected tree)
            adj[a].append(b)
            adj[b].append(a)
        # answer list
        ans=[0]*n 
        # counts the frequency of all letters ('a' => 'z')
        counts=[0]*26

        def dfs(curr_node,parent):
            # get order of a letter ('b'-'a' == 1 || 'c'-'a' == 2,...)
            index=ord(labels[curr_node])-ord('a')
            # we can count the repetition of a letter in a node
            # by the difference in count before & after visiting the subtree
            before=counts[index] # save count of a node before traversing subtree
            counts[index]+=1

            for child in adj[curr_node]:
                
                if child!=parent: # to avoid infine loop
                    dfs(child,curr_node) # parent => curr_node && curr_node => child

            ans[curr_node]=counts[index]-before

        dfs(0,-1) # assumed (-1) as the parent for the root(0)
        return ans