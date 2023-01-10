// Author: Mohamed Amr
// if the frequency of the number is divisible by 3 -> then answer += frequency/3; (best case, greedy).
// else the remainder may equal to 1 or 2.
// in case of 7, 7%3 = 1; in other words 7 = 3 + 3 + 1 which can be converted to 7 = 3 + 2 + 2; therefore ans += s/3 + 1;
// in case of 8, 8%3 = 2; in other words 8 = 3 + 3 + 2 which can be converted to 8 = 3 + 3 + 2; therefore ans += s/3 + 1 also;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // count frequencies of each number
        unordered_map<int,int>occ;
        for(auto& i:tasks)
            occ[i]++;
        
        // Count -> minimum number of steps.
        int count = 0;
        for(auto& [f,s]:occ)
        {
            if(s==1)
                return -1;              // if frequency == 1 , unable to remove the instances of this number
            else if(s%3==0)
                count += s/3;           // if the number is divisible by three, add to the answer frequency/3 (greedy).
            else
            {
                count += s/3+1;         // else if the number is not divisible by three, then the remainder may equal 1 or 2;
            }
        }
        return count;
    }
};