class Solution {
public:
    int countOdds(int low, int high) {
        //if one elem in the interval => return 1 if odd, 0 if even
        if(low == high)
            return low&1 == 1;

        //make sure that low and high both are odd
        //if not: edit the interval and exclude the even ones from it
        if(!(low&1))
            ++low;

        if(!(high&1))
            --high;

        //both odd and equality case?
        if(low == high)
            return 1;

        //2 => low and high
        //(high - low - 1) /2 => no of odd nums in between
        return 2 + (high - low - 1) / 2;
    }
};
