// Author: Ahmed Hossam

class SmallestInfiniteSet {
public:
    // Define a set variable named Mex
    set < int > Mex;

    // Define a constant integer N with a value of 1000
    static constexpr int N = 1000;

    // Constructor function for the SmallestInfiniteSet class
    SmallestInfiniteSet() {
        // Loop through integers from 1 to N and insert them into the set variable Mex
        for(int i = 1; i <= N; i++)
            Mex.insert(i);
    }
    
    // Function to remove and return the smallest integer from the set variable Mex
    int popSmallest() {
        // Store the smallest integer in the set variable Mex
        int mex = *Mex.begin();

        // Remove the smallest integer from the set variable Mex
        Mex.erase(Mex.begin());
        
        // Return the smallest integer
        return mex;
    }
    
    // Function to add an integer back to the set variable Mex
    void addBack(int num) {
        // Insert the integer into the set variable Mex
        Mex.insert(num);
    }
};
