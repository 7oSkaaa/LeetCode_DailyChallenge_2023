// author : Omar Sanad
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // variable n to store the length of the array
        int n = nums.size();

        // a BS function to get the value "k", the index at which the array is rotated.
        auto getK = [&]() {
            int l = 0, r = n - 1, mid, k = 0;
            while (l <= r) {
                mid = (l + r) / 2;
                if (nums[mid] <= nums.back())
                    r = mid - 1, k = mid;
                else
                    l = mid + 1;
            }
            return k;
        };

        int k = getK();

        // a BS function which we use to get the index of the target if it is present in the array
        auto getIdx = [&]() {
            int l = 0, r = n - 1, mid, idx = -1;
            while (l <= r) {
                mid = (l + r) / 2;
                /* Here to make BS on the array like any sorted array, we check the ((i + k) % k)th idx instead of i_th idx*/
                if (nums[(mid + k) % n] >= target)
                    r = mid - 1, idx = nums[(mid + k) % n] == target ? (mid + k) % n : idx;
                else
                    l = mid + 1;
            }

            return idx;
        };

        // return the answer to the problem, In other words, we call the function "getIdx"
        return getIdx();
    }
};
