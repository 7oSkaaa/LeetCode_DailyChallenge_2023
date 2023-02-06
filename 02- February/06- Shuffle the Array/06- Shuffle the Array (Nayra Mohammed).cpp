//Author : Nayra Mohammed

class Solution
{
public:
    /*
        Our array have 2n elements in the form "x1,x2,x3,..,xn,y1,y2,y3,..,yn"
        Considerin' the first half, The i th element form x will face the i th element from y after n steps.
        Our goal is to shuffle our array to be in the form of "x1,y1,x2,y2,...."
        so all we need is to iterate over the first have and take the i th element from x followed by the i th element
        from y  "i th element form y = position of x's element + n"       
    */
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans;// to store the array after the new arrangement
        
        for (int i = 0; i < n; i++) // iterate over the first half
            ans.push_back(nums[i]), ans.push_back(nums[i + n]); //push the i th element form x followed by the it th element from y
        
        return ans;// return the required answer
    }
};
