// Author: Mahmoud Aboelsoud

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        // map to count the number of tasks of the same difficulty
        map<int, int> mp;

        // loop on the tasks to count the number of tasks of the same difficulty
        for(auto&i: tasks)
            mp[i]++;
        
        // all the numbers can be represented as the summation of twos and threes except 1
        
        // to minimize the total number of rounds, you need to increase the number of rounds in which you can complete 3 tasks of the same difficulty 
        // so to do that you will face 3 cases for each difficulty level:
        //    1- the number of tasks is divisible by 3, so it's optimal to finish this tasks in x / 3 rounds
        //    2- the number of tasks is not divisible by 3 with reminder 1, in this case we have x / 3 groups of 3 tasks and 1 task alone 
        //       so in this case we take 1 group from x / 3 groups of 3 tasks making them x / 3 - 1 groups, add that group to the remaining task
        //       and split them into 2 groups of 2 tasks, making the total number of groups in the end ((x / 3 - 1) + 2) = (x / 3 + 1) which can be acheived
        //       with ceil(x / 3)
        //    3- the number of tasks is not divisible by 3 with reminder 2, in this case we have x / 3 groups of 3 tasks and 2 tasks can be grouped in
        //       in 1 group of 2 tasks , making the total number of groups in the end (x / 3 + 1) which can be acheived with ceil(x / 3)

        
        for(auto&[x,y]: mp){
            // 1 can't be represented as the summation of twos and threes so we the solution here is impossible
            if(y == 1) return -1;


            ans += ceil(y / 3.0);
        }

        return ans;
    }
};
