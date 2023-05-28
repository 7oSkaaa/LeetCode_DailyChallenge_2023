// Author: Noura Algohary
class Solution {
public:
    void sort2Vectors(vector<int>& vec1, vector<int>& vec2, int n)
{
    pair<int, int> pairt[n];
 
    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = vec2[i];
        pairt[i].second = vec1[i];
    }
 
    // Sorting the pair array.
    sort(pairt, pairt + n);
     
    // Modifying original vectors
    for (int i = 0; i < n; i++)
    {
        vec2[i] = pairt[i].first;
        vec1[i] = pairt[i].second;
    }
}
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int> pq;
        long long maxProduct = 0, subSum = 0;
        int n = nums2.size();
        
        // sort two vectors according to the second one
        sort2Vectors(nums1, nums2, n);

        // start with the 
        for(int i =n-1 ; i> n-k; i--)
        {
            subSum += nums1[i];
            // negative sign to store nums in ascending order
            pq.push(-nums1[i]);
        }

        for(int i = n-k; i>=0; i--)
        {
            // remove the smallest num from sum 
            subSum += nums1[i];

            // remove the smallest num from priority queue
            pq.push(-nums1[i]);

            if(subSum * nums2[i] > maxProduct)
                maxProduct = subSum * nums2[i];
       
            subSum += pq.top();

            pq.pop();
        }
        return maxProduct;
    }
};