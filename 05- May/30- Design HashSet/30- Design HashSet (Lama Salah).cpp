// Author: Lama Salah

class MyHashSet {
    vector<int> HashSet;  // Vector to store the hash set elements.
public:
    MyHashSet() {
        // Initialize the vector with a size of 1e6 + 5, which is the maximum expected input size.
        HashSet = vector<int>(1e6 + 5);  
    }
    
    void add(int key) {
        // Set the value at the index 'key' to 1 to add the key to the hash set.
        HashSet[key] = 1;  
    }
    
    void remove(int key) {
        // Set the value at the index 'key' to 0 to remove the key from the hash set.
        HashSet[key] = 0;  
    }
    
    bool contains(int key) {
        // Return true if the value at the index 'key' is 1, indicating that the key is present in the hash set.
        return HashSet[key] == 1;  
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();  // Create a new instance of the MyHashSet class
 * obj->add(key);  // Call the add function on the object to add a key to the hash set
 * obj->remove(key);  // Call the remove function on the object to remove a key from the hash set
 * bool param_3 = obj->contains(key);  // Call the contains function on the object to check if a key is present in the hash set
 */
