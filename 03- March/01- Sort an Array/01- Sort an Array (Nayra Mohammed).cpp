//Author: Nayra Mohammed

class Solution
{
public:
    /*
        - We gonna sort our elements using counting sort.
        - Reference : https://www.programiz.com/dsa/counting-sort
        
        Store the occurrence of each element then iterate over the range[nums'minimum element,nums'maximum element]
        - if we find an occurrence of current element in our iteration then we will store it 'his occurrence' times  
    */
    vector<int> sortArray(vector<int> &nums)
    {
        /*    as we have negative values in nums then we need to shift the whole values by 5e4 to positive range temporarily to store its occurrence easily
            so the maximum number in worst case will equal to 10e4
        */
        int mx = 10e4; // maximum number in our range after shifting
        
        vector<int> frq(mx + 1), ans;// frq -> to store the occurrence of nums'elements | ans-> store element's after being sorted
        
        for (auto it : nums)// iterate over nums'elements and update it's occurrence "after shifting them by 5e4"
            frq[it + int(5e4)]++;
        
        for (int i = 0; i <= mx; i++)// iterate over our possible values in nums after shifting
            while (frq[i]--)// if value i occurred in nums then we store it in ans 'his occurrence' times 
                ans.push_back(i - int(5e4)); //we store the actual number before shifting it by 5e4
        
        return ans;// return the sorted array
    }
};
