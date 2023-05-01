# Author: Noura Algohary

class Solution:
    def bulbSwitch(self, n: int) -> int:
        # bulbs are counted (turned on) when it have odd number of divisors
        # only numbers with perfect square roots have odd divisors
        # to count the number of perfect square roots in n,
        # it must be equal to sqrt(n)

        return int(n ** 0.5)
        