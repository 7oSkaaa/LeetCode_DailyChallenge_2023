// Author: Osama Ayman
/**
Initially all are off
Round1: Toggle all bulbs that are divisible by 1 (All bulbs are toggled)
Round2: Toggle all bulbs that are divisible by 2 (2,4,6,..)
.
.
.

To find the number of bulbs that are on after N rounds, those bulbs must have an ODD number of toggles.


Example, N=6

round 1: all are toggled
round 2: 2,4,6 are togggled
round 3: 3, 6 are toggled
round 4: 4 is toggled
round 5: 5 is toggled
round 6: 6 is toggled

In total, 
bulb1 toggled 1 time (ODD)
bulb2 toggled 2 times
bulb3 toggled 2 times
bulb4 toggled 3 times (ODD)
bulb5 toggled 2 times
bulb6 toggled 4 time

So, result is 2 (bulbs 1 and 4)

Observation: the result is the numbers from 1 to N that has odd divisors (factors)
Those numbers are the perfect sqaure numbers. So, find the number of perfect squares from 1 to N. Which is equal to sqrt(n)
 */
class Solution {
    public int bulbSwitch(int n) {
        return (int)Math.sqrt(n);
    }
}