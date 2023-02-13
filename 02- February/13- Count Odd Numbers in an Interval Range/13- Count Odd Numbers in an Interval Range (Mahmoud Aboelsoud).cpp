// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we can only have 3 cases for the interval boundaries:
    // 1- both are even:
    //     let's explain on the test of [2, 8] for example:
    //     2, 3, 4, 5, 6, 7, 8 are the numbers in the interval
    //     we find that we have 3 odd numbers in the interval which is (8 - 2 + 1) / 2
    // 2- both are odd:
    //     let's explain on the test of [1, 7] for example:
    //     1, 2, 3, 4, 5, 6, 7 are the numbers in the interval
    //     we find that we have 4 odd numbers in the interval which is (7 - 1 + 1) / 2 + 1
    // 3- one is even and the other is odd:
    //      let's explain on the test of [1, 8] for example:
    //      1, 2, 3, 4, 5, 6, 7, 8 are the numbers in the interval
    //      we find that we have 4 odd numbers in the interval which is (8 - 1 + 1) / 2

    // so we find that the part of (high - low + 1) / 2 is common for all cases and we only need to add 1 if both are odd

    int countOdds(int low, int high) {
        // so our answer will be (high - low + 1) / 2 + (check if both are odd ? 1 : 0)
        return (high - low + 1) / 2 + ((high & 1) && (low & 1));
    }
};
