// Author: Osama Ayman
class Solution {
    public int countOdds(int low, int high) {
        // count the number of odd numbers up to high (inclusive)
        // count the number of odd numbers up to low (exclusive)
        // subtract lowCount from highCount to get the result
        int highCount = high/2;
        if(high%2==1) highCount++;
        int lowCount = low/2;
        return highCount-lowCount;
    }
}