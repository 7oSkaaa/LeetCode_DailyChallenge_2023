// author : Eman Elsayed

class Solution
{
public:
  // Topics : Sliding Window , Map , Two Pointers
  int totalFruit(vector<int> &nums)
  {
    int ans = 0; // to get maximum length of subbarray  with at most 2 distinct elements
    map<int, int> mp;
    int l = 0, r = 0;
    while (r < nums.size())
    {
      mp[nums[r]]++; // add the current element to the map
      while (l < r && mp.size() > 2)
      { // if the map size is greater than 2 , then we need to remove the first element from the map
        mp[nums[l]]--;
        if (mp[nums[l]] == 0)
          mp.erase(nums[l]); // if the frq of the first element is 0 , then remove it from the map
        l++;
      }
      ans = max(ans, r - l + 1); // update the maximum subbarray with at most 2 distinct elements
      r++;
    }
    return ans; // return the maximum length of subbarray with at most 2 distinct elements
  }
};