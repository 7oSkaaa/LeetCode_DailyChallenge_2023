// author : Omar Sand
/* 
 Imagine we have an array like this
 [10,1,2,7,1,3]
 
 let's sort it
 [1,1,2,3,7,10]

 Now, for any element in the array a[i] 
 if we wanna take in a valid pair, 
 his second element will be either a[i - 1] or a[i + 1]

 So we can just BS on answer (the maximum difference allowed),
 and then try to take the valid pairs, in other words,
 any two adjacent elements whose difference is less than the value that we BS on.

 and if the valid pairs are >= p, then the value that we BS on is good. 
 */
class Solution {
public:
    // declare the variables inside the class itself so that we can use it any where inside the class
    vector < int > v;
    int p;
    
    // a good function, checks if the number of valid pairs, 
    // whose difference is <= diff (the value we BS on),
    // is greater than or equal to "p"
    bool good(int diff) {
        int takenPairs = 0;
        for (int i = 1; i < v.size(); i++)
            if (v[i] - v[i - 1] <= diff)
                takenPairs++, i++;
        return takenPairs >= p;
    }

    // a BS function where we BS on answer
    int bs() {
        int l = 0, r = 1e9, ans = 1e9, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (good(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }

        return ans;
    }

    int minimizeMax(vector<int>& nums, int p) {
        // sort the array
        sort(nums.begin(), nums.end());

        // assign the arguments to the variables declared inside the class 
        this->v = nums;
        this->p = p;

        // return the value of the BS function
        return bs();
    }
};
