<<<<<<< HEAD
// Author: Mohamed Ibrahim
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Create a map of task occurrences
        unordered_map<int, int> taskCnt;
        for(auto& task : tasks)
            taskCnt[task]++;

        // Initialize round counter
        int round = 0;
        for (auto& task : taskCnt) {
            // If a task has less than 2 occurrences, return -1
            if (task.second < 2)       return -1;
            // Increment round counter by the number of rounds needed for the task
            // (task.second/3) is the number of full rounds needed for the task
            // (task.second%3 != 0) is 1 if there is a remainder when dividing the task occurrences by 3
            round += (task.second/3) + (task.second%3 != 0);
        }

        // Return the total number of rounds
        return round;
=======
// Author : Mohamed Ibrahim
// Idea : How to represent a number using values of (2, 3) only in min number of values
/*
 * Solution : 
 * As tasks difficulty doesn't matter here and only 2 or 3 tasks of
 * same difficulty can be done in a round this means we cannot do a single task alone in a round.
 *
 * So we can group tasks with same difficulty & count them then we try to know how many rounds 
 * needed for each group of tasks (with same difficulty) for exmaple if a group `G` of tasks with 
 * difficulty 7 have 10 tasks G = [7,7,7,7,7,7,7,7,7,7] so our problem now to represent the 10 in 
 * terms of 2 & 3 (as this what we call a round).
 *
 * As all numbers except the number `1` can be repesented as a sum of `2` and `3`
 * in other words `x = 2*n + 3*m` where x != 1. In this problem we need `n+m` to be minimum
 * to get `n+m` min we must maximize `m` (the number of rounds where we solve `3` tasks).
 *
 * So we greedily solve each group with 3 tasks at every round unless the last round we need to look
 * if we will `remain` a round at end or not . This is represent by simply divide the group count by
 * 3 & see the remainder for eg. G = [7,7,7,7,7,7,7,7,7,7] then count = 10. and 10 = 2*n + 3*m.
 * So 10/3 = 3 and 10 % 3 == 1 so we cannot solve this group with 3 rounds of 3 tasks we have to 
 * solve only 2 rounds with 3 tasks and 2 rounds with 2 tasks (n = 2, m = 2) ==> (10 = 2*2 + 3*2)
 * 
 * We notice the following : x % 3 can only be 0, 1, 2
 * If x % 3 == 0 ----> (m = x/3,  n = 0) ---> solution = x/3 + 0
 * If x % 3 == 2 ----> (m = x/3,  n = 1) ---> solution = x/3 + 1
 * If x % 3 == 1 ----> (m = x/3 -1,  n = 2) ---> solution = x/3 -1 + 2 = x/3 + 1
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> groups;
        for(int task: tasks){
            groups[task]++;
        }

        int min_rounds = 0;
        for(auto group: groups){
            int task_count = group.second;
            min_rounds += minRoundsFromCount(task_count);
            if(min_rounds < 0) return -1;
        }
        return min_rounds;
    }

    int minRoundsFromCount(int cnt){
        if (cnt == 1) return numeric_limits<int>::min(); // impossible to solve 1 task per round
        int min_rounds = cnt % 3 == 0 ? cnt / 3 : (cnt/3)+1;
        return min_rounds;
>>>>>>> 38e5e0cdd22fd1073ce804486e4f73cceea539cf
    }
};
