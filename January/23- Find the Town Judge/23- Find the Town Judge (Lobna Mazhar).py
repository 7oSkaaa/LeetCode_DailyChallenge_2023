# Author: Lobna Mazhar

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # Make a dictionary to count number of people who trust i
        people = defaultdict(int)

        # For each item in trust, mark the one who is trusting the other by -1 indicating that he can't be the judge as he trusts others, and if the one being trusted has a chance to be the judge (not -1), then increment the count of people who trust him.
        for a,b in trust:
            people[a] = -1
            if people[b] is not -1: people[b] += 1

        # For each person from 1 to n, if the person can be a judge (not marked as -1) and all of the people trust him (count is n - 1 excluding himself), then return that person's index as the judge
        for i in range(1, n + 1):
            if people[i] != -1 and people[i] == n - 1: return i
        # If the judge wasn't found return -1
        return -1