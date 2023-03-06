//Author: Mohamed Ibrahim
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*We use binary search to find the first index start such that the number of missing positive integers before arr[start] is greater than or equal to k. Once we have found this index start, we know that the kth smallest missing positive integer is between arr[start - 1] and arr[start]. Therefore, we can compute the kth smallest missing positive integer as arr[start - 1] + (k - (arr[start - 1] - (start - 1) - 1)) = start + k.*/
        int n = arr.size();
        int s = 0, e = n-1;
        while (s <= e) {
            int m = s+(e-s)/2;
            if (arr[m]-(m+ 1)<k)
                s=m+1;
            else
                e=m-1;
        }
        return s+k;
    }
};