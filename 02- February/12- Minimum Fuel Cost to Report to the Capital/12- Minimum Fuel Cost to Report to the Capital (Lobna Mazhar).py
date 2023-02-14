# Author: Lobna Mazhar

class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        paths = defaultdict(list)
        for road in roads:
            paths[road[0]].append(road[1])
            paths[road[1]].append(road[0])
        
        return self.getCost(paths, 0, seats, set())[0]

    def getCost(self, paths: dict, current: int, seats: int, visited: set) -> tuple[int, int]:
        res, count = 0, 0
        visited.add(current)
        for path in paths[current]:
            if path not in visited:
                new_res, new_count = self.getCost(paths, path, seats, visited)
                res += new_res
                count += new_count
        
        if current != 0: 
            count += 1
            if count > seats: res += (count//seats + (1 if count%seats else 0))
            else: res += 1
        return (res, count)
