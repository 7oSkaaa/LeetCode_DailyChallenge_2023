# LeetCode Daily Challenge Problems for January

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

1. **[Word Pattern](#1--word-pattern)**
1. **[Detect Capital](#2--detect-capital)**
1. **[Delete Column to Make Sorted](#3--delete-column-to-make-sorted)**
1. **[Minimum Rounds to Complete All Tasks](#4--minimum-rounds-to-complete-all-tasks)**
1. **[Minimum Number of Arrows to Burst Balloons](#5--minimum-number-of-arrows-to-burst-balloons)**
1. **[Maximum Ice Cream Bars](#6--maximum-ice-cream-bars)**
1. **[Gas Station](#7--gas-station)**
1. **[Max Points on Line](#8--max-points-on-a-line)**
1. **[Binary Tree Preorder Traversal](#9--binary-tree-preorder-traversal)**
1. **[Same Tree](#10--same-tree)**
1. **[Minimum Time to Collect All Apples in a Tree](#11--minimum-time-to-collect-all-apples-in-a-tree)**
1. **[Number of Nodes in the Sub-Tree With the Same Label](#12--number-of-nodes-in-the-sub-tree-with-the-same-label)**
1. **[Longest Path With Different Adjacent Characters](#13--longest-path-with-different-adjacent-characters)**
1. **[Lexicographically Smallest Equivalent String](#14--lexicographically-smallest-equivalent-string)**
1. **[Number of Good Paths](#15--number-of-good-paths)**
1. **[Insert Interval](#16--insert-interval)**
1. **[Flip String to Monotone Increasing](#17--flip-string-to-monotone-increasing)**
1. **[Maximum Sum Circular Subarray](#18--maximum-sum-circular-subarray)**
1. **[Subarray Sums Divisible by K](#19--subarray-sums-divisible-by-k)**
1. **[Non-decreasing Subsequences](#20--non-decreasing-subsequences)**
1. **[Restore IP Addresses](#21--restore-ip-addresses)**

<hr>

<br><br>

## 1)  [Word Pattern](https://leetcode.com/problems/word-pattern/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`String` `Hash Table`

### Code


```cpp
class Solution {
public:

    // splitting the string into vector of string based on spaces
    vector < string > splitting(string& s){
        string curr;
        vector < string > ret;
        // adding space in the word to split the last word
        s += ' ';
        for(auto& c : s){
            if(c != ' ') curr += c;
            else {
                if(!curr.empty())
                    ret.push_back(curr);
                curr.clear();
            }
        }
        return ret;
    }

    bool wordPattern(string pattern, string s) {
        
        // words seperated by spaces
        vector < string > words = splitting(s);
        
        // check if they are not the same size
        if(words.size() != pattern.size()) return false;

        // character mapping to word and viceversa
        map < char, string > eq;
        map < string, char > mapping;

        for(int i = 0; i < pattern.size(); i++){
            // check if they aren't mapping each other will return false
            if(eq[pattern[i]] != words[i] && !eq[pattern[i]].empty()) return false; 
            else if(mapping.count(words[i]) && mapping[words[i]] != pattern[i]) return false;
            
            // mapping them to each other
            mapping[words[i]] = pattern[i], eq[pattern[i]] = words[i];
        }
        return true;
    }
};
```

<hr>

<br><br>

## 2)  [Detect Capital](https://leetcode.com/problems/detect-capital/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`String`

### Code

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        // count capital letters
        int CapitalLetters =  count_if(word.begin(), word.end(), [&](char c){ 
            return isupper(c); 
        });
        
        // check the three conditions if there is anyone valid
        bool isCapital = false;
        isCapital |= (CapitalLetters == word.size());
        isCapital |= (CapitalLetters == 0);
        isCapital |= CapitalLetters == 1 && isupper(word.front());
        
        // return the answer
        return isCapital;
    }
};
```

<hr>

<br><br>

## 3)  [Delete Column to Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array` `String`

### Code

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // number of columns that aren't sorted
        int deleted_columns = 0;
        
        // dimension of the grid
        int n = strs.size(), m = strs[0].size();
        
        for(int col = 0; col < m; col++){
            
            bool is_current_column_sorted = true;
            // check if the current column is sorted or not
            
            for(int row = 1; row < n; row++)
                is_current_column_sorted &= (strs[row][col] >= strs[row - 1][col]);
            
            // add one to the answer if the current columns isn't sorted
            deleted_columns += !is_current_column_sorted;
        }
        
        // the answer of the problem
        return deleted_columns;
    }
};
```

<hr>

<br><br>

## 4)  [Minimum Rounds to Complete All Tasks](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Hash Table` `Greedy` `Counting`

### Code

```cpp
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        // the frequency of each level
        unordered_map < int, int > freq;

        // make frequency array of tasks -> using map because number in range 10^9
        for(auto& task : tasks)
            freq[task]++;

        // the rounds it takes to complete the tasks
        int rounds = 0;

        // iterate over the map l -> level, f -> frequency of the level
        for(auto& [l, f] : freq){
            // if f = 1 so we can do the missions so will return -1
            if(f == 1)
                return -1;

            // rounds += ceil(f / 3)
            rounds += ((f + 2) / 3);
        }

        // the minimum rounds;
        return rounds;
    }
};
```

<hr>

<br><br>

## 5)  [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Greedy` `Sorting`

### Code

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort the points priority to x_start after that shortest x_end
        sort(points.begin(), points.end(), [&](vector < int >& a, vector < int >& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        int arrows = 1, n = points.size(), farthest_point = points[0][1];
        
        for(int i = 1; i < n; i++){
            
            // start new coverage area with new arrow
            if(points[i][0] > farthest_point)
                farthest_point = points[i][1], arrows++;
            
            // make the farthest points minimum to be the point the cover all previous points with same arrow
            farthest_point = min(farthest_point, points[i][1]);
        }

        // number of arrows;
        return arrows;
    }
};
```

<hr>

<br><br>

## 6)  [Maximum Ice Cream Bars](https://leetcode.com/problems/maximum-ice-cream-bars/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Greedy` `Sorting`

### Code

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sorting the costs to iterate on them in ascending order
        sort(costs.begin(), costs.end());

        // number of ice_creams that will be bought
        int ice_creams = 0;

        for(auto& cost : costs){
            // if my coins can buy this ice_cream so let's by it.
            if(coins >= cost)
                coins -= cost, ice_creams++;
        }

        // the maximum number of ice cream bars
        return ice_creams;
    }
};
```

<hr>

<br><br>

## 7)  [Gas Station](https://leetcode.com/problems/gas-station/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Greedy`

### Code

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // check if impossible to get solution
        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        if(total_gas < total_cost)
            return -1;
        
        int curr_gas = 0, starting_point = 0;
        for(int i = 0; i < n; i++){
            
            // update current amount of gas with the status of the station[i]
            curr_gas += gas[i] - cost[i];

            // update the start point if the last one is invalid
            if(curr_gas < 0)
                curr_gas = 0, starting_point = i + 1;
        }

        return starting_point;
    }
};
```

<hr>

<br><br>

## 8)  [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Hash Table` `Math` `Geometry`


### Code

```cpp
class Solution {
public:

    // Check if three points in the same line
    bool is_same_line(int x1, int y1, int x2, int y2, int x3, int y3){
        return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
    }

    int maxPoints(vector<vector<int>>& points) {
        // inital variables
        int n = points.size(), max_points = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // calculate the number of points that laying in the same line with point[i] and point[j]
                int curr_points = 2;
                for(int k = j + 1; k < n; k++)
                    curr_points += is_same_line(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                
                // update max_points with the maximum that i got.
                max_points = max(max_points, curr_points);
            }
        }

        // maximum points laying in the same line
        return max_points;
    }
};
```

<hr>

<br><br>

## 9)  [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Stack` `Tree` `Depth-First Search` `Binary Tree`



### Code

```cpp
class Solution {
public:

    void preorder(TreeNode* Node, vector < int >& nodes){
        
        // if the current node is nul
        if(Node == nullptr) return;

        // Preorder is RLR -> (Root - Left - Right)
        nodes.push_back(Node -> val);
        preorder(Node -> left, nodes);
        preorder(Node -> right, nodes);
    }

    vector < int > preorderTraversal(TreeNode* root) {
        
        // vector to store the values of the nodes
        vector < int > nodes;
        
        // taverse the tree in pre-order
        preorder(root, nodes);

        return nodes;
    }
};
```

<hr>

<br><br>

## 10)  [Same Tree](https://leetcode.com/problems/same-tree/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Tree` `Breadth-First Search` `Depth-First Search` `Binary Tree`



### Code

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // valid case if the two trees has no nodes in this branch any more
        if(!p && !q) return true;

        // if there is a node difference between the two trees or one branch end before the another one
        if(!p || !q || p -> val != q -> val) return false;

        // check both left and right branches
        return isSameTree(p -> left, q -> left) & isSameTree(p -> right, q -> right);
    }
};
```

<hr>

<br><br>

## 11)  [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Tree` `Breadth-First Search` `Depth-First Search` `Hash Table`



### Code

```cpp
class Solution {
public:

    // global variables for all functions
    vector < vector < int > > adj;
    vector < bool > hasApple;
    vector < int > apples;

    int dfs(int u, int p){
        int time = 0;
        for(auto& v : adj[u]){
            // the child subtree is empty of apples will skip it
            if(v == p || !apples[v]) continue;
            
            // calculate the time of the children
            time += 1 + dfs(v, u);
        }

        // the time is required for this subtree
        return time;
    }

    // get the number of apples in each subtree
    void get_apples(int u, int p){
        apples[u] = hasApple[u];
        for(auto& v : adj[u]){
            // to avoid cycling
            if(v == p) continue;
            // update the current subtree with it's children
            get_apples(v, u);
            apples[u] += apples[v];
        }
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // assign and define the global variables
        this -> hasApple = hasApple;
        adj = vector < vector < int > > (n);
        apples = vector < int > (n);

        // make adjacency list of the tree
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // get number of apples in each subtree
        get_apples(0, -1);

        // the minimum time required
        return 2 * dfs(0, -1);
    }
};
```

<hr>

<br><br>

## 12)  [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Tree` `Breadth-First Search` `Depth-First Search` `Hash Table` `Counting`


### Code

```cpp
class Solution {
public:

    vector < vector < int > > adj, freq;
    vector < int > ans;
    string labels;

    // merge two nodes together
    void merge(vector < int >&  a, vector < int >& b){
        for(int i = 0; i < 26; i++)
            a[i] += b[i];
    }

    // make undirected edge between u and v
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p){
        // add the  current char to the current frequency vector
        freq[u][labels[u] - 'a']++;

        for(auto& v : adj[u]){
            if(v == p) continue;
            dfs(v, u);
            
            // merge the frequencies vectors together
            merge(freq[u], freq[v]);
        }

        // ans[u] is the number of nodes in the subtree with label[u]
        ans[u] = freq[u][labels[u] - 'a'];
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this -> labels = labels;
        adj = vector < vector < int > > (n);
        freq = vector < vector < int > > (n, vector < int > (26)); 
        ans = vector < int > (n);

        // make adjacency list using edges
        for(auto& edge : edges)
            add_edge(edge[0], edge[1]);
        
        // get the answer;
        dfs(0, -1);

        // the required answer
        return ans;
    }
};
```

<hr>

<br><br>

## 13)  [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `String` `Tree` `Depth-First Search` `Graph` `Topological Sort`


### Code

```cpp
class Solution {
public:

    int longestPath(vector<int>& parent, string s) {
        // decalration variables to use
        int n = parent.size();
        vector < int > top_1(n, 1), top_2(n, 1), deg(n);
        
        // add edges between i and parent of i
        for(int i = 1; i < n; i++)
            deg[parent[i]]++;
        
        // queue for topology sort
        queue < int > topo;

        // let's calc the max_path
        int max_path = 1;

        // add the endpoints in queue
        for(int i = 1; i < n; i++)
            if(deg[i] == 0)
                topo.push(i), deg[i]--;
        
        auto update_max = [&](int u, int x){
            // update the maximum to paths for each node
            if(x >= top_1[u])
                top_2[u] = top_1[u], top_1[u] = x;
            else if(x >= top_2[u])
                top_2[u] = x;
        };

        while(!topo.empty() && topo.front()){
            // the current node
            int u = topo.front(), p = parent[u];
            topo.pop();

            // path_length
            int len = 1 + (s[u] != s[p] ? top_1[u] : 0);
            
            // update max paths for current node
            update_max(p, len);

            // if the parent degree becomes 0 so, let's add it
            if(!--deg[p])
                topo.push(p);

            // update the answer wit max between it and the best two paths in it's children
            max_path = max(max_path, top_1[p] + top_2[p] - 1);
        }

        // the length of the longest path with the required conditions.
        return max_path;
    }
};
```

<hr>

<br><br>

## 14)  [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Union Find`


### Code

```cpp
class DSU {
    public:
    vector<int> p;
    DSU(int n = 26) {
	// Initialize the parent vector
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int ascii(char c) {
        return c - 'a';
    }
    int find(char c) {
        return find(ascii(c));
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void merge(char u, char v) {
	/*
	 * 
	 * When merging ... get the parent of both characters and make the smallest one be the parent of all
	 * It guarantees that the parent will be the smallest character in each group
	 *
	 */
        
	int r1 = find(u), r2 = find(v);
        if (r1 < r2) {
            p[r2] = r1;
        }
        else {
            p[r1] = r2;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
	    // Merge each character in s1 to its corresponding character in s2
            dsu.merge(s1[i], s2[i]);
        }
        string ans;
        for (int i = 0; i < int(baseStr.size()); i++) {
	    /*
	     *
	     * Take the parent of the group for each character in baseStr
	     * It guarantees that it will be the lexicographically smallest string
	     *
	     */
            ans += 'a' + dsu.find(baseStr[i]);
        }
        return ans;
    }
};
```

<hr>

<br><br>

## 15)  [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Union Find` `Tree` `Graph`

### Code

```cpp
template < typename T = int, int Base = 0 > struct DSU {
    
    vector < T > parent, Gsize;

    // every element will be equal it's parent and the group size equal 1
    DSU(int MaxNodes){
        parent = Gsize = vector < T > (MaxNodes + 5);
        for(int i = Base; i <= MaxNodes; i++)
          parent[i] = i, Gsize[i] = 1;
    }
    
    // get the leader of each group
    T find_leader(int node){
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // check if the two nodes in the same group
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }

    // merge two groups together
    void union_sets(int u, int v){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if(leader_u == leader_v) return;
        if(leader_u < leader_v) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // get group size
    int get_size(int u){
        return Gsize[find_leader(u)];
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        // number of nodes
        int n = vals.size();

        // adjacent list for each node
        vector < vector < int > > adj(n);

        // dsu structure
        DSU < int > dsu(n);

        // the nodes that equal each value
        map < int, vector < int > >  V_nodes;

        // make edge between the nodes with nodes have value greater than or equal it
        for(auto& edge : edges){
            if(vals[edge[0]] <= vals[edge[1]])
                adj[edge[1]].push_back(edge[0]);
            if(vals[edge[1]] <= vals[edge[0]])
                adj[edge[0]].push_back(edge[1]);
        }

        // add nodes of each value
        for(int i = 0; i < n; i++)
            V_nodes[vals[i]].push_back(i);
        
        // number of good paths equal to n because each node is good path
        int good_paths = n;

        // iterate for each value in ascending order
        for(auto& [val, nodes] : V_nodes){

            // iterate over the nodes with the value val and add the nodes with it's neighbours to merge the groups
            for(auto& u : nodes)
                for(auto& v : adj[u])
                    dsu.union_sets(u, v);

            // make frequency array for the leaders
            unordered_map < int, int >  same_component;
            for(auto& u : nodes)
                same_component[dsu.find_leader(u)]++;

            // add the good paths for each group leader
            for(auto& [leader, cnt] : same_component)
                good_paths += cnt * (cnt - 1) / 2;
        }

        // number of good paths
        return good_paths;
    }
};
```


<hr>

<br><br>

## 16)  [Insert Interval](https://leetcode.com/problems/insert-interval/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array`

### Code

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // add the new interval in the vector of intervals
        intervals.push_back(newInterval);

        // sort the interval to make the new one in the right place
        sort(intervals.begin(), intervals.end());

        // make new vector to insert the marged_intervals in it
        vector < vector < int > > merged;

        // add the first interval to the vector
        merged.push_back(intervals.front());

        for(int i = 1; i < intervals.size(); i++){
            /*
                if the current interval less than or equal the last last time that convered with the merged interval 
                so i will take the max end of the two intervals
                otherwise i will start new interval by pushing it to the merged intervals vector
            */
            if(intervals[i].front() <= merged.back().back()) 
                merged.back().back() = max(merged.back().back(), intervals[i].back());
            else 
                merged.push_back(intervals[i]);
        }

        // the merged vectors
        return merged;
    }
};
```

<hr>

<br><br>

## 17)  [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Dynamic Programming`

### Code

```cpp
class Solution {
public:
    int minFlipsMonoIncr(string& s) {
        
        // number of zeros and ones so far
        int ones = 0, zeros = count(s.begin(), s.end(), '0');

        // store the best answer while traversing
        int min_flips = s.size();

        for(auto& c : s){
            // update number of zeros
            zeros -= (c == '0');

            // update the minimum flips
            min_flips = min(min_flips, ones + zeros);

            // update number of ones while traverse
            ones += (c == '1');
        }

        return min_flips;
    }
};
```

<hr>

<br><br>

## 18)  [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Dynamic Programming`

### Code

```cpp
class Solution {
public:

    // get the maximum subarray sum
    int Max_Subarray_Sum(vector < int >& nums){
        int max_so_far = -1e9, max_curr = 0, DEFAULT = 0;
        for(auto& i : nums){
            // add nums[i] to the current sum
            max_curr += i;

            // update max sum with the maximum between it and current sum 
            max_so_far = max(max_so_far, max_curr);

            // if the current sum < 0 make it 0
            max_curr = max(max_curr, DEFAULT);
        }
        // maximum sum
        return max_so_far;
    }

    // get the minimum subarray sum
    int Min_Subarray_Sum(vector < int >& nums){
        int min_so_far = 1e9, min_curr = 0, DEFAULT = 0;
        for(auto& i : nums){
            // add nums[i] to the current sum
            min_curr += i;

            // update min sum with the minimum between it and current sum 
            min_so_far = min(min_so_far, min_curr);

            // if the current sum < 0 make it 0
            min_curr = min(min_curr, DEFAULT);
        }
        // minimum sum
        return min_so_far;
    }


    int maxSubarraySumCircular(vector<int>& nums) {
        // get the summation of the vector
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // get maximum continous subarray sum
        int max_subarray_sum = Max_Subarray_Sum(nums);
    
        // get minimum continous subarray sum
        int min_subarray_sum = Min_Subarray_Sum(nums);
    
        // the answer will be the max of the maximum or total sum - minimum
        return sum - min_subarray_sum == 0 ? max_subarray_sum : max(max_subarray_sum, sum - min_subarray_sum);
    }
};
```

<hr>

<br><br>

## 19)  [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Hash Table` `Prefix Sum`

### Code

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // store the frequency of sum of the segments
        vector < int > freq(k);
        
        // the current sum of the segment and the number of non-empty subarrays that have a sum divisible by k.
        int current_sum = 0, ans = 0;

        // the base case if the all segment is divisible by k
        freq[0] = 1;
        
        for(auto& x : nums){
            
            // update the current sum and make it in the range of [0, k - 1]
            current_sum  = ((current_sum + x) % k + k) % k;

            // add the number of segment that i can remove the current sum to be equal to zero
            ans += freq[current_sum];

            // add one to the frequency the current sum to 
            freq[current_sum]++;
        }

        // the number of non-empty subarrays that have a sum divisible by k
        return ans;
    }
};
```


<hr>

<br><br>

## 20)  [non-decreasing-subsequences](https://leetcode.com/problems/non-decreasing-subsequences/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Hash Table` `Backtracking` `Bit Manipulation`

### Code

```cpp
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // to store the answer
        vector < vector < int > > inc_sub;
        
        // number of elements
        int n = nums.size();

        for(int mask = 0; mask < (1 << n); mask++){
            // pick the current sub sequence and check if it valid 
            bool is_valid = true;
            vector < int > curr;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    // check if it increasing subsequence or not
                    if(curr.empty() || curr.back() <= nums[i])
                        curr.push_back(nums[i]);
                    else
                        is_valid = false;
                }
            }

            // if it's valid subsequence so we will add it
            if(is_valid && curr.size() > 1)
                inc_sub.push_back(curr);
        }

        // delete the duplicated subsequences
        sort(inc_sub.begin(), inc_sub.end());
        inc_sub.resize(unique(inc_sub.begin(), inc_sub.end()) - inc_sub.begin());
        
        return inc_sub;
    }
};
```

<hr>

<br><br>

## 21)  [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Backtracking` `Bitmasking`

### Code


```cpp
class Solution {
public:

    // return invalid if it's invalid seperation
    string get_ip(vector < int >& part, string& s){
        int n = s.size();
        
        // check if the summation of 4 parts equal to size of the string
        if(n != accumulate(part.begin(), part.end(), 0)) return "invalid";

        // store the ip address will returned and the integer parts
        vector < int > ip(4);
        string ip_address;
        
        
        for(int i = 0, sz = 0; i < 4; sz += part[i], i++){
            // current part after change it to string
            ip[i] = stoi(s.substr(sz, part[i]));

            // check if it in the range between [0, 255]
            if(ip[i] < 0 || ip[i] > 255)
                return "invalid";

            // add this part to the address and if not the last part let's add . to it
            ip_address += to_string(ip[i]) + (i == 3 ? "" : ".");
        }

        // check if there is a part with leading zeros
        return (ip_address.size() - 3 == s.size() ? ip_address : "invalid");
    }

    vector<string> restoreIpAddresses(string& s) {
        // vector to store valid ip addresses
        vector < string > ip_addresses;

        // make 4 nested loop to make 4 parts with these lenghts
        for(int p1 = 1; p1 <= 3; p1++)
            for(int p2 = 1; p2 <= 3; p2++)
                for(int p3 = 1; p3 <= 3; p3++)
                    for(int p4 = 1; p4 <= 3; p4++){

                        // vector to store the size of each part
                        vector < int > part = {p1, p2, p3, p4};

                        // check if it valid seperation
                        string ret = get_ip(part, s);

                        // if it valid so let's add it
                        if(ret != "invalid")
                            ip_addresses.push_back(ret);
                    }

        // valid ip addresses
        return ip_addresses;
    }
};
```
