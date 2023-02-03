# Author: Lobna Mazhar

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        # Make 2 arrays for the distances from node1 to every other node and node2 to every other node
        distances1, distances2 = [-1 for i in range(len(edges))], [-1 for i in range(len(edges))]
        self.getDistance(edges, node1, 0, distances1)
        self.getDistance(edges, node2, 0, distances2)
        
        # for each node if the distance from both node1 and node2 to that node is not -1 which means it is reachable,
        # get the max distance for both of the nodes and if that maximum is less than the current minimum distance,
        # update the minimum reachable distance and the index that can be reached
        index, min_distance = -1, sys.maxsize
        for i in range(len(distances1)):
            if distances1[i] != -1 and distances2[i] != -1:
                max_distance = max(distances1[i], distances2[i])
                if max_distance < min_distance:
                    min_distance = max_distance
                    index = i
        return index

    # Starting from current node, update the distance to the next reachable node
    def getDistance(self, edges, node, distance, distances):
        if node == -1 or distances[node] != -1: return
        
        distances[node] = distance
        self.getDistance(edges, edges[node], distance + 1, distances)
