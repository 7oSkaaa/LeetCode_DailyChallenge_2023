# Author: Lobna Mazhar

class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        red_nodes = defaultdict(list)
        for a,b in redEdges: red_nodes[a].append(b)

        blue_nodes = defaultdict(list)
        for a,b in blueEdges: blue_nodes[a].append(b)

        queue = []
        queue.append((0, False, 0))
        queue.append((0, True, 0))
        ans = [-1]*n
        red_visited, blue_visited = set(), set()
        while queue:
            node, is_red, length = queue.pop(0)
            ans[node] = length if ans[node] is -1 else min(ans[node], length)
            if is_red and node not in red_visited:
                red_visited.add(node)
                for n in blue_nodes[node]:
                    queue.append((n, False, 1 + length))
            elif not is_red and node not in blue_visited:
                blue_visited.add(node)
                for n in red_nodes[node]:
                    queue.append((n, True, 1 + length))
        return ans