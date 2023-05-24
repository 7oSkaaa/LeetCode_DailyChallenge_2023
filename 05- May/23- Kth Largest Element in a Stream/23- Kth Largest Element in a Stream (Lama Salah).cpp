// Author: Lama Salah

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;  // Priority queue to store elements in sorted order.
    int k; // Declares an integer variable k, representing the kth largest element.

public:
    // Constructor of the KthLargest class.
    KthLargest(int k, vector<int>& nums) {
        // Initializes the priority queue pq as a min heap.
        pq = priority_queue<int, vector<int>, greater<int>>(); 
        this->k = k; // Assigns the value of k to the member variable k.

        // Iterate over each element in the vector nums.
        for (auto& i : nums) 
            pq.push(i); // Push the current element into the priority queue pq.

        // Remove the smallest element from pq until its size becomes k.
        while (pq.size() > k) 
            pq.pop(); 
    }
    
    // Add a new value to the KthLargest object.
    int add(int val) {
        pq.push(val); // Push the input value val into the priority queue pq.

        // If the size of pq is greater than k after adding the new value, remove the smallest element from pq.
        if (pq.size() > k)  pq.pop(); 

        // Return the top element of pq, which represents the kth largest element.
        return pq.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */