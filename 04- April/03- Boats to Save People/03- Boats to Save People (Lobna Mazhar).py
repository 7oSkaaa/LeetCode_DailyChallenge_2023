# Author: Lobna Mazhar

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        # Sort list of people
        people.sort()
        start, end = 0, len(people) - 1
        res = 0
        # Starting from the first person and the last person, loop until the pointers cross each other
        while start <= end:
            # If both of them can fit into one boat, increment the start pointer
            if people[end] + people[start] <= limit:
                start += 1
            # Decrement the end pointer in both cases, either they both fit or not as he will need to get into a boat either by himself of with the start person
            end -= 1
            # Increment the result for an extra used boat
            res += 1
        # Return the result
        return res