# LeetCode Daily Challenge Problems for March

<br><br>

## Workflow Checking

<div align="center">
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Author_Line.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Author_Line.yml" taget="_blank"/>
</img>
&nbsp;
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/File_Names.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/File_Names.yml" taget="_blank"/>
</img>
&nbsp;
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Daily_Problem.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Daily_Problem.yml" taget="_blank"/>
</img>
</div>

<br><br>

## Problems:

1. **[Sort an Array](#1--sort-an-array)**
1. **[String Compression](#2--string-compression)**
1. **[Find the Index of the First Occurrence in a String](#3--find-the-index-of-the-first-occurrence-in-a-string)**
1. **[Count Subarrays With Fixed Bounds](#4--count-subarrays-with-fixed-bounds)**
1. **[Jump Game IV](#5--jump-game-iv)**
1. **[Kth Missing Positive Number](#06--kth-missing-positive-number)**
1. **[Minimum Time to Complete Trips](#07--minimum-time-to-complete-trips)**
1. **[Koko Eating Bananas](#08--koko-eating-bananas)**
1. **[Linked List Cycle II](#09--linked-list-cycle-ii)**
1. **[Linked List Random Node](#10--linked-list-random-node)**
1. **[Convert Sorted List to Binary Search Tree](#11--convert-sorted-list-to-binary-search-tree)**
1. **[Merge k Sorted Lists](#12--merge-k-sorted-lists)**
1. **[Symmetric Tree](#13--symmetric-tree)**
1. **[Sum Root to Leaf Numbers](#14--sum-root-to-leaf-numbers)**
1. **[Check Completeness of a Binary Tree](#15--check-completeness-of-a-binary-tree)**
1. **[Construct Binary Tree from Inorder and Postorder Traversal](#16--construct-binary-tree-from-inorder-and-postorder-traversal)**
1. **[Implement Trie (Prefix Tree)](#17--implement-trie-prefix-tree)**
1. **[Design Browser History](#18--design-browser-history)**
1. **[Design Add and Search Words Data Structure](#19--design-add-and-search-words-data-structure)**
1. **[Can Place Flowers](#20--can-place-flowers)**
1. **[Number of Zero-Filled Subarrays](#21--number-of-zero-filled-subarrays)**
1. **[Minimum Score of a Path Between Two Cities](#22--minimum-score-of-a-path-between-two-cities)**
1. **[Number of Operations to Make Network Connected](#23--number-of-operations-to-make-network-connected)**
1. **[Reorder Routes to Make All Paths Lead to the City Zero](#24--reorder-routes-to-make-all-paths-lead-to-the-city-zero)**
1. **[Count Unreachable Pairs of Nodes in an Undirected Graph](#25--count-unreachable-pairs-of-nodes-in-an-undirected-graph)**
1. **[Longest Cycle in a Graph](#26--longest-cycle-in-a-graph)**
1. **[Minimum Path Sum](#27--minimum-path-sum)**
1. **[Minimum Cost For Tickets](#28--minimum-cost-for-tickets)**
1. **[Reducing Dishes](#29--reducing-dishes)**
1. **[Scramble String](#30--scramble-string)**
1. **[Number of Ways of Cutting a Pizza](#31--number-of-ways-of-cutting-a-pizza)**

<hr>

<br><br>

## 1)  [Sort an Array](https://leetcode.com/problems/sort-an-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Divide and Conquer` `Sorting` `Heap (Priority Queue)` `Merge Sort` `Bucket Sort` `Radix Sort` `Counting Sort`

### Code


```cpp
class Solution {
public:

    void Merge(int l, int m, int r, vector < int >& nums){
        // [l, m] and [m + 1, r] are sorted
        int sz_1 = m - l + 1, sz_2 = r - m;
        
        // left and right are temporary arrays
        
        vector < int > left(sz_1), right(sz_2);
        // copy the elements to the temporary arrays
        for(int i = 0; i < sz_1; i++) left[i] = nums[l + i];
        for(int i = 0; i < sz_2; i++) right[i] = nums[m + 1 + i];
        
        // merge the temporary arrays to be sorted array
        int i = 0, j = 0, k = l;
        while(i < sz_1 && j < sz_2)
            nums[k++] = (left[i] <= right[j] ? left[i++] : right[j++]);
        
        // copy the remaining elements
        while(i < sz_1) nums[k++] = left[i++];
        while(j < sz_2) nums[k++] = right[j++];
        // the array is now sorted
    }

    void Merge_Sort(vector < int >& nums, int l, int r){
        // base case is when the array has only one element
        if(l >= r) return;

        // divide the array into two parts
        int m = l + (r - l) / 2;

        // sort the two parts
        Merge_Sort(nums, l, m);
        Merge_Sort(nums, m + 1, r);

        // merge the two parts
        Merge(l, m, r, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        Merge_Sort(nums, 0, n - 1);
        return nums;
    }
};
```

<hr>

<br><br>

## 2)  [String Compression](https://leetcode.com/problems/string-compression/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Two Pointers`

### Code


```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1, index = 0;
        
        auto add_new_group = [&](char c){
            // make the current char of the new array equal c
            chars[index++] = c;

            // the number of element in the group more than 1 add the freq
            if(cnt > 1){
                for(auto& cc : to_string(cnt))
                    chars[index++] = cc;
            }

            // reset the number of elements in the group
            cnt = 1;
        };

        // loop over the chars and checks the consecutive characters
        for(int i = 1; i < chars.size(); i++){
            // if the current char equal the last one so we will add to the current group
            // otherwise we will start new group
            if(chars[i] == chars[i - 1])
                cnt++;
            else 
                add_new_group(chars[i - 1]);
        }

        // add the remainig characters
        add_new_group(chars.back());

        return index;
    }
};
```

<hr>

<br><br>

## 3)  [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Two Pointers` `String` `String Matching`

### Code


```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        // just use find builtin function
        int idx = haystack.find(needle);

        // string::npos means that we cannot find the subtring
        return (idx == string::npos ? -1 : idx);
    }
};
```
<hr>

<br><br>

## 4)  [Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Queue` `Sliding Window` `Monotonic Queue`

### Code


```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), minPos = -1, maxPos = -1, leftBound = -1;
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            
            // the index of the last invalid bound
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            // update min position
            if (nums[i] == minK) 
                minPos = i;
            
            // update max position
            if (nums[i] == maxK)
                maxPos = i;

            // add the number of subarrays that i will be the right bound of them
            res += max(0, min(maxPos, minPos) - leftBound);
        }
        
        return res;
    }
};
```
<hr>

<br><br>

## 5)  [Jump Game IV](https://leetcode.com/problems/jump-game-iv/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `Breadth-First Search`

### Code


```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        // number of elements
        int n = arr.size();

        // adjacent list for each number with the indices that appears in it
        map < int, vector < int > > adj;
        for(int i = 0; i < n; i++)
            adj[arr[i]].push_back(i);

        // make distance vector to get the minimum distance for each index
        vector < int > dist(n, 1e9);

        // make bfs started from index 0
        queue < int > bfs;
        bfs.push(0);
        dist[0] = 0;

        // to check it's valid indices to add to the current queue or not
        auto add = [&](int u, int v) -> void {
            if(v < 0 || v >= n) return;
            if(dist[v] > dist[u] + 1)
                dist[v] = dist[u] + 1, bfs.push(v);
        };

        // make bfs to get the minimum distance for each index
        while(!bfs.empty()){
            // the current index
            int u = bfs.front();
            bfs.pop();

            // check can i add the next index to me
            add(u, u + 1);

            // check can i add the prev index to me
            add(u, u - 1);

            // try to move to the index of any element same number of me
            for(auto& v : adj[arr[u]])
                add(u, v);

            // clear the adjacent list for the current element to avoid redundancy
            adj[arr[u]].clear();
        }

        // return the minimum distance to reach last element
        return dist[n - 1];
    }
};
```

<hr>
<br><br>

## 06)  [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        /*
            we will make BS on asnwer to get the kth missing number
            I try to make sequence of consecutive number it will be 
            - 1 2 3 4 5 6 7 8 9 .......
            my array will be 
            - 2 3 4 7 11

            i will try to check the second element in my array the difference between it
            and my second element in the sequence will be the number of missing elements
            untill this element

            if the answer will be -1 so the answer will be out of the array 
        */

        // the bounds of the search
        int n = a.size(), l = 1, r = n, ans = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            (a[m - 1] - m < k ? l = m + 1, ans = m : r = m - 1);
        }
        return ans + k;
    }
};
```
    

<hr>
<br><br>

## 07)  [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // check the current time
        auto is_good = [&](long long t){
            // to store number of trips can make with this time
            long long ach_trips = 0;
            for(auto& bus : time)
                ach_trips += t / bus;
            // if the number of trips greater than totalTrips so it's good time
            return ach_trips >= totalTrips;
        };
        
        // search for the minimum time to make total trips with buses
        long long l = 1, r = 1, min_time = -1;

        // to get best r
        while(!is_good(r)) r *= 2;

        while(l <= r){
            long long m = l + (r - l) / 2;
            // if the time m can acheive so try number less than it to achieve best time
            (is_good(m) ? r = m - 1, min_time = m : l = m + 1);
        }

        // the minimum time for all buses to complete totalTrips
        return min_time;
    }
};
```
    
<hr>
<br><br>

## 08)  [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:

    // return the ceiling of the division between a and b 
    inline int ceil(const int& a, const int& b){
        return (a + b - 1) / b;
    }

    int minEatingSpeed(vector<int>& piles, int& h) {
        auto is_good = [&](int k){
            int total_hours = 0;
            /*
                loop over the piles and calculate the total hours needed to eat
                all the bananas such that each hour you will eat number of bananas <= k
            */
            for(auto& p : piles){
                total_hours += ceil(p, k);
                if(total_hours > h)
                    return false;
            }
            
            // if the number of hours less than h so k is valid choice
            return total_hours <= h;
        };

        // make binary search to get the least valid choice
        int l = 1, r = 1, k = -1;

        // make r less power of 2 valid number
        while(!is_good(r)) r *= 2;

        while(l <= r){
            int m = l + (r - l) / 2;
            (is_good(m) ? r = m - 1, k = m : l = m + 1);
        }

        // the minimum valid k
        return k;
    }
};
```
    
<hr>
<br><br>

## 09)  [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `Linked List` `Two Pointers`

### Code


```cpp
class Solution {
public:
    
    ListNode* find_cycle(ListNode* head, unordered_map < ListNode*, bool >& occ){
        // return the node if it is visited before
        if(!head || occ[head]) return head;
        
        // mark this node as visited node
        occ[head] = true;

        return find_cycle(head -> next, occ);
    }
    
    ListNode *detectCycle(ListNode *head) {
        // map to store the visited nodes
        unordered_map < ListNode*, bool > occ;

        // the node that make cycle
        return find_cycle(head, occ);
    }
};
```

<hr>
<br><br>

## 10)  [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Linked List` `Math` `Reservoir Sampling` `Randomized`

### Code


```cpp
class Solution {
public:
    
    // vector  to push the number in it
    vector < int > nums;
    
    Solution(ListNode* head) {
        // loop over the list and add the number in it
        ListNode* curr = head;
        while(curr != nullptr)
            nums.push_back(curr -> val), curr = curr -> next;
    }
    
    int getRandom() {
        // get the size of the list and return a random number from it with equal probability
        int sz = nums.size();
        return nums[rand() % sz];
    }
};
```

<hr>
<br><br>

## 11)  [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Linked List` `Divide and Conquer` `Tree` `Binary Search Tree` `Binary Tree`

### Code


```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // vector to store the numbers in sorted form
        vector < int > nums;

        // loop over the list and make the numbers sorted
        ListNode* curr = head;
        while(curr != nullptr){
            // add the current number and move to the next number
            nums.push_back(curr -> val);
            curr = curr -> next;
        }

        // the BST Tree
        return construct(0, nums.size() - 1, nums);
    }

    TreeNode* construct(int l, int r, vector < int >& nums){
        // the base if the left pointer greater than right pointer
        if(l > r) return nullptr;
        
        // middle of the current subarray
        int m = l + (r - l) / 2;

        // the middle element will be the root of this subarray
        TreeNode* root = new TreeNode(nums[m]);

        // construct the left subtree with same concept
        root -> left = construct(l, m - 1, nums);

        // construct the right subtree with same concept
        root -> right = construct(m + 1, r, nums);

        // return the root of the current subtree
        return root;
    }
};
```
<hr>
<br><br>

## 12)  [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Linked List` `Divide and Conquer` `Heap (Priority Queue)` `Merge Sort`

### Code


```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // initial the current node in the list
        ListNode* root = nullptr;

        // let us save the index of the minimum element of the current head list of lists
        int idx = -1;

        for(int i = 0; i < lists.size(); i++){
            // if the current list is empty skip it
            if(lists[i] == nullptr) continue;

            // if it's the first list we found or it's minimum than the minimum of we found update the index
            if(idx == -1 || lists[i] -> val < lists[idx] -> val)
                idx = i;
        }

        // if there are no lists anymore
        if(idx == -1) return nullptr;

        // update the current node with the minimum value of the minimum node
        root = new ListNode(lists[idx] -> val);

        // move the minimum node to it's next
        lists[idx] = lists[idx] -> next;

        // the next of the current node in the new list will be the returned node of the next step
        root -> next = mergeKLists(lists);

        // return the current node of the new list
        return root;
    }
};
```

<hr>
<br><br>

## 13)  [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    
    
    bool traverse(TreeNode* node1, TreeNode* node2){
        // if the two subtrees are empty so they are symmetric
        if(!node1 && !node2) return true;

        // if one of the two nodes empty so the subtree not symmetric
        if(!node1 || !node2) return false;

        // if the value of the two subtrees root different the subtrees aren't symmetric
        if(node1 -> val != node2 -> val) return false;

        // if the left tree and right tree are symmetric so the current subtree are symmetric also
        return traverse(node1 -> right, node2 -> left) && traverse(node1 -> left, node2 -> right);
    }
    
    bool isSymmetric(TreeNode* root) {
        // if the tree are empty 
        if(!root) return true;

        // check the symmetry of the tree
        return traverse(root -> left, root -> right);
    }
};
```
<hr>
<br><br>

## 14)  [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    // we just need to traverse the tree and keep track of the current value of concatenation of the nodes from the root to the current node
    // when we reach a leaf node, we add the current value to the answer
    

    // the answer variable
    int ans;

    // the dfs function to traverse the tree
    void dfs(TreeNode* root, int val){
        // if the current node is null, we return
        if(root == NULL) return;

        // we concatenate the current node value to the current value
        val = val * 10 + root -> val;

        // if we reach a leaf node, we add the current value to the answer
        if(!root -> left && !root -> right) ans += val;
        
        // we traverse the left and right subtrees
        dfs(root -> left, val);
        dfs(root -> right, val);
    }

    int sumNumbers(TreeNode* root) {
        // we initialize the answer to zero
        ans = 0;
        // we call the dfs function to traverse the tree and calculate the answer
        dfs(root, 0);
        
        // we return the answer
        return ans;
    }
};
```
<hr>
<br><br>

## 15)  [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Tree` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    bool isCompleteTree(TreeNode* root, bool isHaveRight = false) {
        // try to bfs about the tree to get all levels
        queue < TreeNode* > bfs;

        // add the root to start the bfs from it
        bfs.push(root);

        // if the previous node have missed one right sub-tree
        bool isNodeMissed = false;

        while(!bfs.empty()){
            // get the current size of the queue
            int sz = bfs.size();

            // add node and check the state
            auto add_node = [&](TreeNode* node){
                // if the current node is nullptr so there is a missed node right now
                if(!node)
                    return isNodeMissed = true;

                // if we have to add a node and there is a node missed before so it's not completed tree
                if(isNodeMissed)
                    return false;

                // add the current node because it's valid to add
                return bfs.push(node), true;
            };

            while(sz--){
                TreeNode* curr = bfs.front();
                bfs.pop();

                // to check the current root is valid or not
                bool valid_root = true;

                valid_root &= add_node(curr -> left);
                valid_root &= add_node(curr -> right);

                // if the current root not valid so it's not completed tree
                if(!valid_root)
                    return false;
            }
        }

        // ok, it's a completed tree right now.
        return true;
    }
};
```

<hr>
<br><br>

## 16)  [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `Divide and Conquer` `Tree` `Binary Tree`

### Code


```cpp
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # If the inorder array is empty, return an empty tree
        if len(inorder) == 0: return None
        # If the inorder array has 1 element, return it as the only node (root)
        if len(inorder) == 1: return TreeNode(inorder[0])
        
        # Mark the root as the last node in the postorder array (left,right,parent)
        root = TreeNode(postorder[-1])
        # Traverse the inorder array to find the left subtree which will be all the nodes before the root node (the last node in the post order)
        for i in range(len(inorder)):
            # If current node is the root
            if inorder[i] == postorder[-1]:
                # Build the left subtree using the inorder and postorder nodes right before the root using the current index i
                root.left = self.buildTree(inorder[:i], postorder[:i])
                # Build the right subtree using the inorder nodes right after the root using the current index i and the postorder nodes from index i to the end
                root.right = self.buildTree(inorder[i+1:], postorder[i:-1])
        return root
```
<hr>
<br><br>

## 17)  [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `String` `Design` `Trie`

### Code


```cpp
class Trie {

    // the node class that represents each node in the trie data structure
    class Node {
    public:
        // the children of the node (one for each letter in the alphabet)
        Node* children[26];

        // a boolean variable that indicates if the node is the end of a word or not
        bool is_end;

        // the constructor of the node class
        Node() {
            // initialize the children of the node to null
            for(auto& i : children) {
                i = nullptr;
            }
            // initialize the is_end variable to false
            is_end = false;
        }
    };

    // the root node of the trie data structure
    Node* root;
public:

    // the constructor of the trie data structure
    Trie() {
        // initialize the root node to a new node (the root node is a dummy node)
        root = new Node();
    }
    
    // the insert function that inserts a word in the trie data structure
    void insert(string word) {
        // start from the root node
        auto curr = root;

        // loop over the word
        for(int i = 0; i < word.size(); i++) {
            // if the current node doesn't have a child with the current letter of the word then create a new node
            if(not curr -> children[word[i] - 'a'])
                curr -> children[word[i] - 'a'] = new Node();
        
            // move to the child of the current node with the current letter of the word
            curr = curr -> children[word[i] - 'a'];
        }

        // mark the last node as the end of a word
        curr -> is_end = true;
    }
    
    // the search function that searches for a word in the trie data structure
    bool search(string word) {
        // start from the root node
        auto curr = root;

        // loop over the word
        for(int i = 0; i < word.size(); i++) {
            // if the current node doesn't have a child with the current letter of the word then return false
            if(not curr -> children[word[i] - 'a'])
                return false;
            
            // move to the child of the current node with the current letter of the word
            curr = curr -> children[word[i] - 'a'];
        }

        // return true if the last node is the end of a word and false otherwise
        return curr -> is_end;
    }
    
    // the startsWith function that searches for a prefix in the trie data structure
    bool startsWith(string prefix) {
        // start from the root node
        auto curr = root;

        // loop over the prefix
        for(int i = 0; i < prefix.size(); i++) {
            // if the current node doesn't have a child with the current letter of the prefix then return false
            if(not curr -> children[prefix[i] - 'a'])
                return false;

            // move to the child of the current node with the current letter of the prefix
            curr = curr -> children[prefix[i] - 'a'];
        }

        // since we reached the end of the prefix then return true (the prefix exists)
        return true;
    }
};
```
<hr>
<br><br>

## 18)  [Design Browser History](https://leetcode.com/problems/design-browser-history/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Linked List` `Stack` `Design` `Doubly-Linked List` `Data Stream`

### Code


```cpp
// Author: Ahmed Hossam

class BrowserHistory {
public:
    
    // to store the size and current index of the tab
    int sz, currIdx;

    // to store the urls 
    vector < string > history;

    // constructor to initialize the vector with homepage
    BrowserHistory(string& homepage) {
        history.push_back(homepage);
        sz = 1, currIdx = 0;
    }

    void visit(const string& url) {
        // If the user has gone back in history and is now adding a new URL, 
        // the forward history from the current position should be removed.
        if(currIdx + 1 < history.size())
            history[++currIdx] = url, sz = currIdx + 1;
        else 
            history.push_back(url), sz++, currIdx++;
    }
    
    // This function moves the user back in the history by the specified number of steps.
    // If the user has reached the beginning of the history, it returns the first URL in the history.
    string back(int steps) {
        currIdx = max(currIdx - steps, 0);
        return history[currIdx];
    }
    
    // This function moves the user forward in the history by the specified number of steps.
    // If the user has reached the end of the history, it returns the last URL in the history.
    string forward(int steps) {
        currIdx = min(currIdx + steps, sz - 1);
        return history[currIdx];
    }
};
```
<hr>
<br><br>

## 19)  [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Depth-First Search` `Design` `Trie`

### Code


```cpp
template < int Mode = 0 > struct Trie {
    // Mode [lowercase, uppercase, digits]
    static constexpr int sz[4] = {26, 26, 10};

    struct Node {

        // declare array of nodes with requires size
        Node* child[sz[Mode]];
        bool is_word;
        int freq;
 
        Node(){
            memset(child, 0, sizeof(child));
            is_word = false;
            freq = 0;
        }
    };

    // declare the base root
    Node* root;
    char DEFAULT;

    Trie(){
        root = new Node;
        DEFAULT = "aA0"[Mode];
    }
    
    // insert a word in the trie
    void insert(const string& word){
        Node* curr = root;
        for(auto& c : word){
            // if this char in this position not appeared before let's create it
            if(!curr -> child[c - DEFAULT]) 
                curr -> child[c - DEFAULT] = new Node;
            // move to the next position
            curr = curr -> child[c - DEFAULT];
            // update the frequency of the current string
            curr -> freq++;
        }
        curr -> is_word = true;
    }
    
    // search for a string in the Trie
    bool search(const string& word, int idx, Node* curr){
        // if we reach the final of the string let's return if it was a word or not
        if(idx == word.size()) return curr -> is_word;

        // if the current char is a lowercase letter
        if(word[idx] != '.'){
            // let us check if it is already found so check the next letter otherwise retrun false
		    if(!curr -> child[word[idx] - DEFAULT]) return false;
		    return search(word, idx + 1, curr -> child[word[idx] - DEFAULT]);
        }else {
            // if the current char is a wildcard
            bool answer = false;
            // let's check all the possible letters
            for(auto& node : curr -> child){
                if(node)
                    if(search(word, idx + 1, node))
                        return true;
            }
            return answer;
        }
    }

    // overloading function to the user to use
    bool search(const string& word){
        return search(word, 0, root);
    }
 
};

class WordDictionary {
public:

    // trie to store the strings
    Trie < > trie;

    WordDictionary() {
        trie = Trie < 0 > ();
    }
    
    void addWord(const string& word) {
        // add the current word to the trie
        trie.insert(word);
    }
    
    bool search(const string& word) {
        // search about this word can we got it or not
        return trie.search(word);
    }
};
```
<hr>
<br><br>

## 20)  [Can Place Flowers](https://leetcode.com/problems/can-place-flowers/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Greedy`

### Code


```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // insert 0 at the back of the vector
        flowerbed.push_back(0);

        // insert 0 at the front of the vector
        flowerbed.insert(flowerbed.begin(), 0);

        // check every subarray with size 3 if all of them = 0
        for(int i = 1; i < flowerbed.size() - 1; i++){
            if(!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i + 1]){
                // if is valid subarray so make the middle of them equal 1
                flowerbed[i] = 1, n--;
            }
        }

        // if we can put n flowers in the array
        return n <= 0;
    }
};
```
<hr>
<br><br>

## 21)  [Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Math`

### Code


```cpp
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // Define a vector to store the number of zeros between two non-zero numbers
        vector < int > zeros;
        // Define a variable to store the number of consecutive zeros
        int curr_zeros = 0;
        // Loop through the input vector and count the number of consecutive zeros
        for(auto& x : nums){
            // If the current number is not zero and we have counted some consecutive zeros before
            if(x != 0 && curr_zeros)
                // Add the number of consecutive zeros to the zeros vector and reset the counter
                zeros.push_back(curr_zeros), curr_zeros = 0;
            // If the current number is zero, increment the counter
            else if(x == 0)
                curr_zeros++;
        }
        // Add the final count of consecutive zeros to the zeros vector
        zeros.push_back(curr_zeros);
        // Define a variable to store the total number of zero-filled subarrays
        long long subarrays = 0;
        // Loop through the zeros vector and calculate the number of zero-filled subarrays for each count of consecutive zeros
        for(auto& z : zeros)
            subarrays += (1LL * z * (z + 1)) / 2;
        // Return the total number of zero-filled subarrays
        return subarrays; 
    }
};
```
<hr>
<br><br>

## 22)  [Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Union Find` `Graph`

### Code


```cpp
template < typename T = int, int Base = 1 > struct DSU {
    
    vector < T > parent, Gsize, Min;

    // Constructor: initializes parent and Gsize vectors to store the nodes and their sizes, 
    // and initializes Min vector with very large values.
    DSU(int MaxNodes){
        parent = Gsize = vector < T > (MaxNodes + 5);
        Min = vector < T > (MaxNodes + 5, 1e9);
        // Initializes each node to be its own parent and its size to be 1.
        for(int i = Base; i <= MaxNodes; i++)
          parent[i] = i, Gsize[i] = 1;
    }
    
    // Finds the leader (or root) of the set that the node belongs to, 
    // and compresses the path to the leader for optimization.
    T find_leader(int node){
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Checks if two nodes are in the same set.
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }

    // Merges two sets that contain nodes u and v, and updates the minimum weight 
    // of the edge that connects them.
    void union_sets(int u, int v, int w){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        // Update the minimum weight of the edge that connects the two sets.
        Min[leader_u] = Min[leader_v] = min({Min[leader_u], Min[leader_v], w});
        // If the two nodes are already in the same set, we don't need to merge them.
        if(leader_u == leader_v) return;
        // Merge the smaller set into the larger set to keep the tree balanced.
        if(Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Returns the size of the set that the node belongs to.
    int get_size(int u){
        return Gsize[find_leader(u)];
    }

    // Returns the minimum weight of the edge that connects the set that the node belongs to with any other set.
    int get_min(int u){
        return Min[find_leader(u)];
    }
};

class Solution {
public:

    // Solves the problem of finding the minimum score in a graph after removing a single edge.
    int minScore(int n, vector<vector<int>>& roads) {
        DSU < int > dsu(n);
        // Union all edges in the graph.
        for(auto& r : roads)
            dsu.union_sets(r[0], r[1], r[2]);
        // Return the minimum weight of the edge that connects the set that contains node n with any other set.
        return dsu.get_min(n);
    }
};
```

<hr>
<br><br>

## 22)  [Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Union Find` `Graph`

### Code


```cpp
template < typename T = int, int Base = 1 > struct DSU {
    
    vector < T > parent, Gsize, Min;

    // Constructor: initializes parent and Gsize vectors to store the nodes and their sizes, 
    // and initializes Min vector with very large values.
    DSU(int MaxNodes){
        parent = Gsize = vector < T > (MaxNodes + 5);
        Min = vector < T > (MaxNodes + 5, 1e9);
        // Initializes each node to be its own parent and its size to be 1.
        for(int i = Base; i <= MaxNodes; i++)
          parent[i] = i, Gsize[i] = 1;
    }
    
    // Finds the leader (or root) of the set that the node belongs to, 
    // and compresses the path to the leader for optimization.
    T find_leader(int node){
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Checks if two nodes are in the same set.
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }

    // Merges two sets that contain nodes u and v, and updates the minimum weight 
    // of the edge that connects them.
    void union_sets(int u, int v, int w){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        // Update the minimum weight of the edge that connects the two sets.
        Min[leader_u] = Min[leader_v] = min({Min[leader_u], Min[leader_v], w});
        // If the two nodes are already in the same set, we don't need to merge them.
        if(leader_u == leader_v) return;
        // Merge the smaller set into the larger set to keep the tree balanced.
        if(Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Returns the size of the set that the node belongs to.
    int get_size(int u){
        return Gsize[find_leader(u)];
    }

    // Returns the minimum weight of the edge that connects the set that the node belongs to with any other set.
    int get_min(int u){
        return Min[find_leader(u)];
    }
};

class Solution {
public:

    // Solves the problem of finding the minimum score in a graph after removing a single edge.
    int minScore(int n, vector<vector<int>>& roads) {
        DSU < int > dsu(n);
        // Union all edges in the graph.
        for(auto& r : roads)
            dsu.union_sets(r[0], r[1], r[2]);
        // Return the minimum weight of the edge that connects the set that contains node n with any other set.
        return dsu.get_min(n);
    }
};
```

<hr>
<br><br>

## 23)  [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Union Find` `Graph`

### Code


```cpp
// A template class for Disjoint Set Union (DSU) data structure
template < typename T = int, int Base = 0 > struct DSU {
    vector < T > parent, Gsize; // Parent and size vectors to store the parent of each node and the size of each set

    // Constructor to initialize the parent and Gsize vectors
    DSU(int MaxNodes) {
        // Allocate memory for parent and Gsize vectors
        parent = Gsize = vector < T >(MaxNodes + 5); 

        // Initially, set the parent of each node to itself and the size of each set to 1
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Function to find the leader (root) of the set that the given node belongs to
    T find_leader(int node) {
        // Path compression optimization
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Function to check if two nodes are in the same set
    bool is_same_sets(int u, int v) {
        // Check if both nodes have the same leader (root)
        return find_leader(u) == find_leader(v);
    }

    // Function to merge two sets containing the given nodes
    void union_sets(int u, int v) {
        // Find the leaders of the sets containing u and v
        int leader_u = find_leader(u), leader_v = find_leader(v);

        // If they are already in the same set, nothing to do
        if (leader_u == leader_v) return;

        // Merge the smaller set into the larger set
        if (Gsize[leader_u] < Gsize[leader_v]) 
            swap(leader_u, leader_v);

        // Update the size of the merged set
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU < int > dsu(n);

        // Merge the sets containing each pair of connected nodes
        for (auto& vec : connections)
            dsu.union_sets(vec[0], vec[1]);

        int connected = 0;

        // Count the number of connected components
        for (int i = 0; i < n; i++)
            if (dsu.find_leader(i) == i)
                connected++;

        // If there are not enough edges to connect all nodes, return -1
        if (connections.size() < n - 1)
            return -1;

        // Return the number of redundant edges needed to connect all nodes
        return connected - 1;
    }
};
```
    
<hr>
<br><br>

## 24)  [Reorder Routes to Make All Paths Lead to the City Zero](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Graph`

### Code


```cpp
class Solution {
public:
    
    // adjacency list to store the graph
    vector < vector < int > > adj;
    
    // visited array to mark nodes as visited during dfs
    vector < bool > vis;

    // dfs function to traverse the graph and count the number of edges to reverse
    int dfs(int u){
        // convert negative nodes to positive
        u = abs(u);
        // count the number of edges to reverse
        int cnt = 0;
        // mark node as visited
        vis[u] = true;
        // iterate over all adjacent nodes
        for(auto& v :  adj[u]){
            // skip if node has already been visited
            if(vis[abs(v)]) continue;
            // recursively traverse the graph and count the number of edges to reverse
            cnt += dfs(v) + (v > 0);
        }
        // return the total number of edges to reverse
        return cnt;
    }

    // function to find the minimum number of edges to reverse
    int minReorder(int n, vector < vector < int > > &connections){
        // initialize the adjacency list and visited array
        adj = vector < vector < int > > (n);
        vis = vector < bool > (n);
        // add edges to the adjacency list with appropriate signs
        for(auto& vec : connections){
            // add forward edge
            adj[vec[0]].push_back(vec[1]);
            // add reverse edge
            adj[vec[1]].push_back(-vec[0]);
        }
        // perform dfs from vertex 0 and return the total number of edges to reverse
        return dfs(0);
    }
};
```
    

<hr>
<br><br>

## 25)  [Count Unreachable Pairs of Nodes in an Undirected Graph](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Union Find` `Graph`

### Code


```cpp
// Define a class for Disjoint Set Union (DSU)
template < typename T = int, int Base = 0 > struct DSU {
    // Declare a vector to store the parent and size of each node
    vector < T > parent, Gsize;

    // Constructor for DSU class
    DSU(int MaxNodes) {
        // Initialize the parent and Gsize vector with Base and 1 respectively
        parent = Gsize = vector < T > (MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Function to find the leader of the set to which a node belongs
    T find_leader(int node) {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Function to check if two nodes belong to the same set or not
    bool is_same_sets(int u, int v) {
        // if the two nodes have the same leader so they are in the same set
        return find_leader(u) == find_leader(v);
    }

    // Function to union the sets of two nodes
    void union_sets(int u, int v) {
        // Find the leaders of the sets to which the two nodes belong
        int leader_u = find_leader(u), leader_v = find_leader(v);
        // If the two nodes belong to the same set so there is no need to union them
        if (leader_u == leader_v) return;
        // Union the two sets by attaching the smaller set to the larger set
        if (Gsize[leader_u] < Gsize[leader_v]) 
            swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Function to get the size of the set to which a node belongs
    int get_size(int u) {
        return Gsize[find_leader(u)];
    }
};

class Solution {
public:
    // Function to count the number of pairs of nodes such that they belong to different components
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Create an instance of the DSU class
        DSU < int > dsu(n);
        // Union the sets of all nodes in the given edges
        for (auto& edge : edges)
            dsu.union_sets(edge[0], edge[1]);
        // Create a map to store the number of nodes in each component
        unordered_map < int, int > components;
        for (int i = 0; i < n; i++)
            components[dsu.find_leader(i)]++;
        // Calculate the number of pairs of nodes such that they belong to different components
        long long ans = 0;
        for (auto& [leader, sz] : components)
            ans += 1ll * sz * (n - sz);

        // Return the number of pairs of nodes such that they belong to different components
        return ans / 2;
    }
};
```
    
<hr>
<br><br>

## 26)  [Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Depth-First Search` `Graph` `Topological Sort`

### Code


```cpp
class Solution {
public:
    int LC, id;
    vector < int > path, edges, vis;

    // Helper function to perform DFS traversal
    void dfs(int u, int len) {
        // Set path length for current node
        path[u] = len;
        // Mark current node as visited in current DFS traversal
        vis[u] = id;

        // If current node has no outgoing edge, return
        if (edges[u] == -1)
            return;

        // Get next node in the cycle
        int v = edges[u];

        // If next node hasn't been visited yet, continue DFS traversal from next node
        if (path[v] == -1) 
            dfs(v, len + 1);
        // If next node has been visited in current traversal and is on a shorter path to the start node
        else if (path[v] < path[u] && vis[u] == vis[v])
            // Update longest cycle length
            LC = max(LC, len + 1 - path[v]);
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        // Initialize path lengths and visited nodes to -1
        path = vis = vector < int > (n, -1);
        this -> edges = edges;
        LC = -1, id = 0;

        // Iterate through all nodes in the graph
        for (int i = 0; i < n; i++) {
            // If node hasn't been visited yet, perform DFS traversal from that node and increment ID
            if (path[i] == -1)
                dfs(i, 0), id++;
        }

        // the longest Cycle in the graph
        return LC;
    }
};
```
    
<hr>
<br><br>

## 27)  [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Matrix`

### Code


```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Get the dimensions of the grid
        int n = grid.size(), m = grid[0].size();
        
        // Initialize a 2D vector 'dp' to store minimum path sums for each cell in the grid
        // 'dp' is initialized to a large value so that it can be easily updated with smaller values later
        vector < vector < int > > dp(n + 5, vector < int > (m + 5, 1e9));
        
        // Initialize the top-left and top-right cells to 0, since the minimum path sum to those cells is 0
        dp[0][1] = dp[1][0] = 0;
        
        // Iterate through each cell in the grid
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                // Calculate the minimum path sum to reach the current cell
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) +  grid[i - 1][j - 1];
                // The above line of code calculates the minimum path sum to reach the cell (i,j) in the grid
                // It does this by comparing the minimum path sum to reach the cell above (i-1, j) and the cell to the left (i, j-1)
                // The minimum path sum is then updated to include the current cell's value (grid[i-1][j-1])
        
        // Return the minimum path sum to the bottom-right cell (i.e., the last element in 'dp')
        return dp[n][m];
    }
};
```
    
<hr>
<br><br>

## 28)  [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // A function that takes in a vector of days and a vector of costs and returns the minimum cost of tickets.
    int mincostTickets(vector < int >& days, vector < int >& costs) {
        // n is the size of the days vector.
        int n = days.size();
        
        // dp is a vector of size n+5 initialized to 0, where dp[i] represents the minimum cost of tickets starting from day i.
        vector < int > dp(n + 5, 0);
        
        // Starting from the end of the days vector, iterate through each day backwards.
        for(int idx = n - 1; idx >= 0; idx--){
            
            // tempidx is a variable to store the index of the day after the current day that needs to be covered by the ticket.
            int tempidx = -1;

            // Calculate the index of the first day that needs to be covered by a ticket that is valid for 1 day.
            tempidx = lower_bound(days.begin() + idx, days.end(), days[idx] + 1) - days.begin();
            
            // Calculate the cost of the ticket that covers only one day, and add the cost to the minimum cost starting from tempidx.
            int first = costs[0] + dp[tempidx];
            
            // Calculate the index of the first day that needs to be covered by a ticket that is valid for 7 days.
            tempidx = lower_bound(days.begin() + idx, days.end(), days[idx] + 7) - days.begin();
            
            // Calculate the cost of the ticket that covers 7 days, and add the cost to the minimum cost starting from tempidx.
            int second = costs[1] + dp[tempidx];
            
            // Calculate the index of the first day that needs to be covered by a ticket that is valid for 30 days.
            tempidx = lower_bound(days.begin() + idx, days.end(), days[idx] + 30) - days.begin();
            
            // Calculate the cost of the ticket that covers 30 days, and add the cost to the minimum cost starting from tempidx.
            int third = costs[2] + dp[tempidx];
            
            // Store the minimum cost among the three options in dp[idx], which represents the minimum cost starting from day idx.
            dp[idx] = min(first, min(second, third)); 
        }

        // Return the minimum cost starting from day 0, which is stored in dp[0].
        return dp[0];
    }
};
```
    
<hr>
<br><br>

## 29)  [Reducing Dishes](https://leetcode.com/problems/reducing-dishes/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Greedy` `Sorting`

### Code


```cpp
class Solution {
public:

    int maxSatisfaction(vector < int >& a) {                
        // size of the satisfaction vector
        int n = a.size();
        
        // sorting the satisfaction vector in non-decreasing order
        sort(a.begin(), a.end());

        // initializing variables for storing maximum satisfaction, current sum, and total sum
        int MaxAns = 0, currSum = 0, Sum = 0;
        
        // iterating over the dishes in reverse order
        for(int i = n - 1; i >= 0; i--){
    
            // adding the satisfaction of the current dish to the current sum
            currSum += a[i];
    
            // adding the current sum to the total sum
            Sum += currSum;
    
            // updating the maximum satisfaction with the maximum of current and previous satisfactions
            MaxAns = max(MaxAns, Sum);
        }

        // returning the maximum satisfaction for cooking the dishes with minimum time 1
        return MaxAns;
    }
};
```
    
<hr>
<br><br>

## 30)  [Scramble String](https://leetcode.com/problems/scramble-string/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`String` `Dynamic Programming`

### Code


```cpp
class Solution {
public:

    // Define a unordered_map called dp to store previously calculated results
    unordered_map < string , bool > dp;

    // A recursive function to determine if s1 is a scramble of s2
    bool solve(const string& s1, const string& s2){
        // If s1 and s2 are equal, return true
        if(s1 == s2) return true;

        // If the size of s1 is less than or equal to 1, return false
        if( s1.size() <= 1) return false;
        
        // Create a key using s1 and s2 and check if it already exists in the unordered_map dp. 
        // If it exists, return the value
        string key = s1 + '#' + s2;
        if(dp.count(key)) return dp[key];

        // Get the size of s1
        int n = s1.size();
        
        for(int i = 1 ; i <= n - 1; i++){
            // Check if s1[0:i] is a scramble of s2[n-i:i] and s1[i:n] is a scramble of s2[0:n-i]
            if(solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i)))
                // If it is a scramble, set the value of key to true and return it
                return dp[key] = true;
            
            // Check if s1[0:i] is a scramble of s2[0:i] and s1[i:n] is a scramble of s2[i:n]
            if(solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i)))
                // If it is a scramble, set the value of key to true and return it
                return dp[key] = true;
        }

        // If none of the above conditions are true, set the value of key to false and return it
        return dp[key] = false;
    }

    // A function to determine if s1 is a scramble of s2
    bool isScramble(const string& s1, const string& s2) {
        // If the size of s1 is not equal to the size of s2, return false
        if(s1.size() != s2.size())
            return false;
        
        // Call the solve function and return its value
        return solve(s1, s2);
    }
};
```
    
<hr>
<br><br>

## 31)  [Number of Ways of Cutting a Pizza](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Memoization` `Matrix`

### Code


```cpp
class Solution {

    // define long long 
    #define ll long long 

    // constant number for MOD
    static constexpr int MOD = 1e9 + 7;

    // Define a private function to add two long integers
    void add(ll &a, ll &b) { 
        a += b;
        if(a >= MOD)
            a -= MOD;
    }

public:
    // Define a public function to count the number of ways to split the matrix
    int ways(vector<string>& A, int K) {
        // Get the matrix size
        int M = A.size(), N = A[0].size();

        // Define a 2D vector cnt to count the number of 'A's in the submatrix from (i, j) to (M, N)
        vector < vector < int > > cnt(M + 1, vector < int >(N + 1));

        // Calculate cnt using a nested loop
        for (int i = M - 1; i >= 0; --i) {
            int s = 0;
            for (int j = N - 1; j >= 0; --j) {
                s += A[i][j] == 'A';
                cnt[i][j] = cnt[i + 1][j] + s;
            }
        }

        // Define a 3D vector dp to store the number of ways to split the submatrix from (i, j) to (M, N) into K submatrices
        vector < vector < vector < ll > > > dp(M + 1, vector < vector < ll > >(N + 1, vector < ll > (K + 1)));
       
        // Calculate dp using nested loops
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                // Initialize the base case
                dp[i][j][1] = cnt[i][j] > 0;
                
                // Calculate dp using nested loops
                for (int k = 2; k <= K; ++k) {
                    for (int t = i + 1; t < M; ++t) {
                        // Skip invalid splits
                        if (cnt[i][j] == cnt[t][j]) continue;
                        if (cnt[t][j] == 0) break;
                        // Update dp
                        add(dp[i][j][k], dp[t][j][k - 1]);
                    }

                    for (int t = j + 1; t < N; ++t) {
                        // Skip invalid splits
                        if (cnt[i][j] == cnt[i][t]) continue;
                        if (cnt[i][t] == 0) break;
                        // Update dp
                        add(dp[i][j][k], dp[i][t][k - 1]);
                    }
                }
            }
        }

        // Return the number of ways to split the whole matrix into K submatrices
        return dp[0][0][K];
    }
};
```
    