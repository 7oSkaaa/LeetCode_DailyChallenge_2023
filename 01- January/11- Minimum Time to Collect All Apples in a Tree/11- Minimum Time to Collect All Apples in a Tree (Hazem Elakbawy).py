# Author : Hazem Elakbawy
class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj={i:[] for i in range (n)} # create adjaceny list
        for a,b in edges:
        # append in both directions (undirected tree)
            adj[a].append(b) 
            adj[b].append(a)
        
        def dfs(curr_node:int,parent:int)->int:
            time=0
            for child in adj[curr_node]:
                # to avoid infine loop we check if child equal to its parent
                if child == parent:
                    continue
                # recurse on curr_node(as the parent) && child (as child for curr_node)
                childtime=dfs(child,curr_node)
                # no child time and no apples ==> time=0
                # else ==> overall time += (childtime+2) 
                if childtime or hasApple[child]:
                    time+= 2+childtime
            return time
            # root of tree has no parent (assume -1)
        return dfs(0,-1)
