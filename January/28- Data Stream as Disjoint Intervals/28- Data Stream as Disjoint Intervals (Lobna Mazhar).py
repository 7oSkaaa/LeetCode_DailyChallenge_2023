# Author: Lobna Mazhar

class SummaryRanges:

    def __init__(self):
        self.intervals = []
        self.values = set()
        

    def addNum(self, value: int) -> None:
        # Keep track of the inserted values to avoid searching for the same value multiple times
        # If the given value exists, return else add it and continue updating the intervals
        if value in self.values: return
        self.values.add(value)

        # Get available index to insert given value
        index, overlapping = self.findIndex(self.intervals, value)
       
        # If the index is out of range then append it to the end of the list (new larger value)
        if index == len(self.intervals):
            self.intervals.append([value, value])
        # If the index is -1 then insert it to the start of the list (new smaller value)
        elif index == -1:
            self.intervals.insert(0, [value, value])
        else:
            # if the index overlaps another interval, edit the index's start and end by the minimum and maximum of the value and the index's interval range
            if overlapping:
                self.intervals[index] = [min(self.intervals[index][0], value), max(self.intervals[index][1], value)]
            
                # Merge intervals, if current edited index not matched with previous, try to match with next
                # Always, a maximum of one interval will be merged with the current edited one
                if not self.merge(self.intervals, index - 1, index):
                    self.merge(self.intervals, index, index + 1)
            # if not overlapping, insert the value at the given index
            else:
                self.intervals.insert(index, [value, value])

    # Apply binary search to find suitable index to insert current value returning the found index and a boolean to indicate if the index is overlapping with another interval or not
    def findIndex(self, intervals, value):
        start, end = 0, len(intervals) - 1
        while start <= end:
            middle = start + (end - start + 1) // 2
            if value == intervals[middle][0] - 1 or value == intervals[middle][1] + 1:
                return middle, True
            elif value < intervals[middle][0]:
                end = middle - 1
            elif value > intervals[middle][1]:
                start = middle + 1
        return start, False

    # Merge 2 intervals if they overlap
    def merge(self, intervals, first, second):
        if first < 0 or second == len(intervals): return False
        if intervals[first][1] == intervals[second][0] - 1:
            intervals[first] = [intervals[first][0], intervals[second][1]]
            del intervals[second]
            return True
        else: return False

    def getIntervals(self) -> List[List[int]]:
        return self.intervals
        


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()