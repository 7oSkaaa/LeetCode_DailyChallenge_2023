// Author: Ahmed Hossam

class MyHashSet {
public:

    // Declare an unordered_set named hash_set to store integers
    unordered_set<int> hash_set;

    MyHashSet() {
        // Initialize the unordered_set using the default constructor
        hash_set = unordered_set < int > ();
    }
    
    void add(int key) {
        // Insert the given key into the hash_set
        hash_set.insert(key);
    }
    
    void remove(int key) {
        // Remove the given key from the hash_set
        hash_set.erase(key);
    }
    
    bool contains(int key) {
        // Check if the given key exists in the hash_set and return true if it does, false otherwise
        return hash_set.count(key);
    }
};
