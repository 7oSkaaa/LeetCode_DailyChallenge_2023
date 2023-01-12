# LeetCode Daily Challenge Problems for January

<br><br>

## Workflow Checking

<div align="center">
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Checker.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Checker.yml" taget="_blank"/>
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

hr>

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

hr>

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

hr>

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


hr>

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


hr>

<br><br>

## 12)  [number-of-nodes-in-the-sub-tree-with-the-same-label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

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
