// Author : Mohamed Ibrahim
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
    }
};
