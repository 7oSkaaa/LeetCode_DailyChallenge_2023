//Author: WalaaAbdElhady

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        //iterate from right to left to sum
        for (int i = num.size() - 1; i >= 0; i--) {
           //every time sum k + num[i]
            num[i] += k;
            //update k to sum it with next element
            k = num[i] / 10;
            //Remove carry from element
            num[i] %= 10;
        }
        //if k in not over iterate to sum it
        while (k) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        //return the vector after update
        return num;
    }
};