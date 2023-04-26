# Author: Noura Algohary
class SmallestInfiniteSet:
    # use list as a set 
    st = []

    def __init__(self):
        self.st.clear()

        for i in range(1, 1001):
            self.st.append(i)
        

    def popSmallest(self) -> int:
        # sort to return the first element(smallest element)
        self.st.sort()

        removed = self.st.pop(0)

        return removed

    def addBack(self, num: int) -> None:
        # make sure the number is not presented in the set
        if num not in self.st:
            self.st.insert(0, num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)