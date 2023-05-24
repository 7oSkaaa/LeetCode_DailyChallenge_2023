// Author: Ahmed Hossam

class KthLargest {
public:
    
    // Priority queue to store the kth largest elements
    priority_queue < int, vector < int >, greater < int > > pq;
    int k;

    // Constructor to initialize the object with k and a vector of numbers
    KthLargest(int k, vector < int >& nums) {
        this -> k = k;
        
        // Add all the numbers to the priority queue
        for(auto& x : nums)
            add(x);
    }
    
    // Function to add a new value to the priority queue and return the kth largest element
    int add(int val) {
        // Add the new value to the priority queue
        pq.push(val);  
        
        // Remove the smallest element if the size exceeds k
        if(pq.size() > k)
            pq.pop();
        
        // Return the current kth largest element
        return pq.top();  
    }
};
