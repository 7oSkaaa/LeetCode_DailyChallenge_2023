// Author: Ahmed Hossam

class Node {
public:
    int key, val;
    Node *next, *prev;
    Node(int key = -1, int val = -1) {
        this -> key = key;
        this -> val = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

class LRUCache {
public:
    static constexpr int N = 1e4 + 5;
    int maxCap, currSz; // Maximum capacity of the cache
    vector < Node* > nodes; // Map to store key-node pairs
    Node *head = new Node(); // Dummy head node for doubly-linked list
    Node *tail = new Node(); // Dummy tail node for doubly-linked list

    // Constructor to initialize the LRUCache with a given capacity
    LRUCache(int capacity) {
        maxCap = capacity, currSz = 0;
        head -> next = tail;
        tail -> prev = head;
        nodes = vector < Node* > (N, nullptr);
    }

    // Function to add a new node after the head node in the doubly-linked list
    void addNode(Node *newNode) {
        Node *temp = head -> next;
        head -> next = newNode;
        newNode -> next = temp;
        newNode -> prev = head;
        temp -> prev = newNode;
    }

    // Function to delete a node from the doubly-linked list
    void deleteNode(Node *delNode) {
        Node *prev = delNode -> prev;
        Node* next = delNode -> next;
        prev -> next = next;
        next -> prev = prev;
    }

    // Function to retrieve the value associated with the given key
    int get(int key) {
        if (!nodes[key]) return -1; // Key not found in cache
        Node *node = nodes[key];
        deleteNode(node); // Move the accessed node to the front
        addNode(node);
        nodes[key] = head -> next; // Update the position in the cache
        return nodes[key] -> val; // Return the value associated with the key
    }

    // Function to insert or update a key-value pair in the cache
    void put(int key, int value) {
        if (nodes[key]) {
            Node *node = nodes[key];
            deleteNode(node); // Remove the existing node
            node -> val = value; // Update the value of the existing node
            addNode(node); // Move the node to the front
            nodes[key] = head -> next; // Update the position in the cache
        } else {
            if (currSz == maxCap) {
                Node *prev = tail -> prev; // Remove the least recently used node
                deleteNode(prev);
                Node *newNode = new Node(key, value); // Create a new node with the given key and value
                addNode(newNode); // Add the new node to the front
                nodes[prev -> key] = nullptr; // Remove the old key from the cache
                nodes[key] = head -> next; // Update the position in the cache
            } else {
                Node *newNode = new Node(key, value); // Create a new node with the given key and value
                addNode(newNode); // Add the new node to the front
                nodes[key] = head -> next; // Update the position in the cache
                currSz++;
            }
        }
    }
};
