# Author: Lobna Mazhar

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        # Prepare a counter for each task type
        tasks_counter = defaultdict(int)
        for task in tasks:
            tasks_counter[task] += 1
        
        res = 0
        # Loop on the tasks_counter checking each task's count
        for task in tasks_counter:
            # If the task's count is 1 then return -1 as it can't form any round        
            if tasks_counter[task] == 1: return -1
            # Divide the task's count by 3 which represents the number of rounds needed to finish n rounds with 3 tasks per round.
            res += tasks_counter[task] // 3
            # Check if there is a remainder tasks after dividing by 3, it will have 3 cases:
            #  0 -> No remainder, no more rounds are needed
            #  1 -> 1 more round is needed which will include 2 tasks; the remaining task with one task from the previous calculated round (one round from the 3-tasks round will be 2-tasks and the 3rd task will be added to the current round)
            #  2 -> 1 more round is needed including the last 2 remaining tasks
            remainder = tasks_counter[task] % 3
            # In the case that we have more than 0 remaining tasks (1 or 2) we need 1 more round
            if remainder > 0: res += 1
        # Return the final result representing the total number of rounds needed
        return res