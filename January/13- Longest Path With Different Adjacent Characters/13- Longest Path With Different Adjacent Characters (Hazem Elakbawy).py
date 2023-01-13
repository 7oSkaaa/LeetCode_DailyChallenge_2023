# Author : Hazem Elakbawy
class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        graph=defaultdict(list)
        index=0
        # (self.res) rather than (res) to use it inside dfs func
        self.res=1
        # create graph
        for i in parent:
            graph[parent[index]].append(index)
            index+=1
        # total result will be (longest + second longest + 1)
        def dfs(node):
            longest=sec_longest=0
            for child in graph[node]:
                path=dfs(child)
                # if it's a valid path (child character != node character)
                if s[child]!=s[node]:
                    # path > longest
                    if path>longest:
                        sec_longest=longest
                        longest=path
                    # sec_longest < path <= longest
                    elif path > sec_longest:
                        sec_longest=path
            # update result with the max value
            self.res=max(self.res,longest+sec_longest+1)
            return longest+1 # including the node itself
        dfs(0) # start from root
        return self.res
