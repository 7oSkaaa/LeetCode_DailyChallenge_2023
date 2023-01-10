# Author: Mohamed Aly Elsayed Matar

# at first I came up with more complicated solution with double for loops but it gave me time limit exceeded error
# so I searched how people thought for a better solution for this problem and I found this
# I tried it on paper first, it was really a fun method, and after I fully understand it it I wrote the code
# so if you didn't get the idea from the first time try to write it down on paper

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        # get the frequency of number of each task and stored it in a dictionary by using the Counter function
        data = Counter(tasks)
        # our round counter
        round = 0
        # check the dictionary values if it contains an occurrence of 1, if so return -1
        if 1 in data.values():
            return -1
        # iterate over each value occurrence
        for level in data.values():
            # if the value is 2 then we will need only 1 round
            if level == 2:
                round += 1
            # now our three cases
            # note: i used // instead of / in dividing because // returns integers only without the decimals
            # 1st: if the value is divisible by 3 like 6, then the rounds we need is the value divided by 3
            elif (level % 3) == 0:
                round += (level // 3)
            # 2nd: if the value-1 is divisible by 3 like 7, then the rounds we need is the value divided by 3 + 1
            elif ((level-1) % 3) == 0:
                round += (level // 3) + 1
            # 3rd: if the value-2 is divisible by 3 like 8, then the rounds we need is the value divided by 3 + 1
            elif ((level-2) % 3) == 0:
                round += (level // 3) + 1
        return round