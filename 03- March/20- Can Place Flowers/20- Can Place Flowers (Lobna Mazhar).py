# Author: Lobna Mazhar

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        index = 0
        # Loop on all the slots until reaching the end of the flowerbed or no remaining flowers need to be planted
        while n > 0 and index < len(flowerbed):
            # If the current plot is not planted and the previous plot, if exists, is not planted either and the next plot, if exists, is not planted as well, mark the plot as planted and decrement the flowers count n by 1
            if flowerbed[index] is 0 and (index - 1 < 0 or flowerbed[index - 1] is 0) and (index + 1 >= len(flowerbed) or flowerbed[index + 1] is 0):
                flowerbed[index] = 1
                n -= 1
            # Move to the next plot
            index += 1
        # If all the flowers were planted, return True
        return n is 0