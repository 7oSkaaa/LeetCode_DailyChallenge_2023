# Author: Lobna Mazhar

class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        # Set start and end boundaries to min and maximum expected times, 1 and max time multiplied by total no of trips
        start, end = 1, totalTrips * max(time)
        # Do binary search until finding the most suitable time to achieve the required no of trips
        while start < end:
            middle = start + (end - start - 1) // 2
            
            # Compute the total no of trips that can be achieve at time middle
            # For each bus, the no of trips completed at time middle is time middle divided by bus time t
            no_of_completed_trips_by_middle = 0
            for t in time: no_of_completed_trips_by_middle += middle // t
            
            # If no of trips is less than the required, update the start boundary to middle time + 1
            # Else update the end boundary to be at the max with time middle
            if no_of_completed_trips_by_middle < totalTrips: start = middle + 1
            else: end = middle
        
        # Return the current start time as the minimum time required to complete totalTrips
        return start


        