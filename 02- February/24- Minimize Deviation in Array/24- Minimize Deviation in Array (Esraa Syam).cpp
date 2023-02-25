// author: Esraa Syam
class Solution {
public:
    /*
      solution idea :
        1. use set to automatically sort the elements in descending order
        2. if the element is odd, multiply it by 2
        3. find the deviation between the largest and smallest element
        4. while the largest element is even, divide it by 2 and insert it back into the set
        5. get the minimum deviation 
    */
    int minimumDeviation(vector<int>& nums) {
        set < int , greater < int > > s;
        for(auto & i : nums){
            if(i & 1) i *= 2;
            s.insert(i);
        }
        int deviation = *s.begin() - *s.rbegin();
        while(*s.begin() % 2 == 0){ // while the largest element is even
            int x = *s.begin();
            s.erase(x); // erase the largest element
            x /= 2; 
            s.insert(x); // insert element after dividing it by 2
            deviation = min(deviation, *s.begin() - *s.rbegin()); // get the minimum deviation
        }
        return deviation;
    }
};