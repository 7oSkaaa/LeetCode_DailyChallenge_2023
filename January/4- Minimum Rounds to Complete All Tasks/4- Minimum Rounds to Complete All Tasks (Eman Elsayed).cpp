// Author: Eman El Sayed

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int cnt = 0;
        map<int, int> mp; // Store the frequencies in the map.
        for (auto &i : tasks)
            mp[i]++;

        // Iterate over the task's frequencies
        for (auto &i : mp)
        {
            // If the frequency is 1, it's not possible to complete tasks
            if (i.second == 1)
            {
                return -1;
            }
            // Group all the tasks in triplets to get minimum Rounds
            cnt += i.second / 3;
            /*
                 If count % 3 = 1 , groups of triplets and 2 pairs.
                 Ex : tasks = [5 , 5 , 5 , 5]
                 we divide it to groups [5 , 5] , [5 , 5] is correct [5, 5, 5][5] is not
                 If count % 3 = 2 , groups of triplets and 1 pair
                 Ex : tasks = [5, 5, 5, 5, 5]
                 we divide it to groups [5, 5, 5][5 , 5]
                 NOTE: COUNT % 3  , the result always will be 0 , 1 , 2
            */
            if (i.second % 3 != 0)
                cnt++;
        }
        // Return the Answer of the Problem
        return cnt;
    }
};
