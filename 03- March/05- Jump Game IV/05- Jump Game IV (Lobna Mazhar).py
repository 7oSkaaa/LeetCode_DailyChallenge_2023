# Author: Lobna Mazhar

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        # Keep track of different indicies of each number
        num_indicies = defaultdict(list)
        for i in range(len(arr)): num_indicies[arr[i]].append(i)

        # Apply BFS to reach the last index, append the inidices that helps in reaching that index
        queue, visited = [], set()
        queue.append((len(arr) - 1, 0))
        visited.add(len(arr) - 1)
        while queue:
            # Pop the current index to be reached
            index, count = queue.pop(0)
           
            # If the current index is 0, return the count (The Final Answer)
            if index is 0: return count

            # Check the same indices with the same exact value as that at the current index and add them to the queue
            # Delete the list of indices for the current value from the table to be marked as investigated and added to the queue
            for i in num_indicies[arr[index]]:
                if i not in visited: 
                    queue.append((i, count + 1))
                    visited.add(i)
            del num_indicies[arr[index]]

            # Add the previous index if in range and it wasn't visited
            if (index - 1) >= 0 and (index - 1) not in visited:
                queue.append((index - 1, count + 1))
                visited.add(index - 1)
                
            # Add the next index if in range and it wasn't visited                
            if (index + 1) < len(arr) and (index + 1) not in visited:
                queue.append((index + 1, count + 1))
                visited.add(index + 1)
