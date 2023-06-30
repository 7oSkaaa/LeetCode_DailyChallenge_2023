# Author: Noura Algohary
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        highest = altitude = 0

        for i in gain:
            # each altitude's height is the summation of the previous altitude 
            # and the net gain between i and the previous altitude
            altitude += i

            # store the highest one found in highest 
            if altitude > highest:
                highest = altitude

        return highest