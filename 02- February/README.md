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

1. **[Greatest Common Divisor of Strings](#1--greatest-common-divisor-of-strings)**
1. **[Verifying an Alien Dictionary](#2--verifying-an-alien-dictionary)**
1. **[Zigzag Conversion](#3--zigzag-conversion)**
1. **[Permutation in String](#4--permutation-in-string)**
1. **[Find All Anagrams in a String](#5--find-all-anagrams-in-a-string)**
1. **[Shuffle the Array](#6--shuffle-the-array)**
1. **[Fruit Into Baskets](#7--fruit-into-baskets)**
1. **[Jump Game II](#8--jump-game-ii)**
1. **[Naming a Company](#9--naming-a-company)**
1. **[As Far from Land as Possible](#10--as-far-from-land-as-possible)**
1. **[Shortest Path with Alternating Colors](#11--shortest-path-with-alternating-colors)**
1. **[Minimum Fuel Cost to Report to the Capital](#12--minimum-fuel-cost-to-report-to-the-capital)**

<hr>

<br><br>

## 1)  [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Math`

### Code


```cpp
class Solution {
public:

    /*
        str1 = mGCD, str2 = nGCD, str1 + str2 = (m + n) x GCD = str2 + str1
    */
    
    string gcdOfStrings(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        return (s1 + s2 == s2 + s1 ? s2.substr(0, __gcd(n, m)) : "");
    }
};
```

<hr>

<br><br>

## 2)  [Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`String` `Array`  `Hash Table`

### Code

```cpp
class Solution {
public:
    
    // to save the ordered of each charachter
    vector < int >  ord;
    
    bool isSmaller(string& a, string& b){

        // loop for the minimum size between them
        for(int i = 0; i < min(a.size(), b.size()); i++){
            // if the ordered of the char of the first word is smaller than the right word so return false
            // if the ordered of the char of the first word is bigger than the right word so return true
            // if they are the same skip this character
            if(ord[a[i] - 'a'] < ord[b[i] - 'a']) 
                return false;
            else if(ord[a[i] - 'a'] > ord[b[i] - 'a']) 
                return true;
        }

        // if the all character are same so return if the left word size greatet than or equal
        return a.size() >= b.size();
    }

    bool isAlienSorted(vector<string>& words, string& order) {
        ord = vector < int > (26);
        
        // assign each character with its order
        for(int i = 0; i < order.size(); i++)
            ord[order[i] - 'a'] = i + 1;

        // compare each two consecutive words if the left word is smaller than right word
        for(int i = 1; i < words.size(); i++)
            if(!isSmaller(words[i], words[i - 1])) 
                return false;
        
        return true;
    }
};
```

<hr>

<br><br>

## 3)  [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String`

### Code


```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        // If the number of rows is 1, the pattern will be a straight line,
        // so we can simply return the original string
        if (numRows == 1) return s;

        // Create a vector of strings, where each element represents a row
        vector<string> rows(min(numRows, int(s.size())));

        // curRow keeps track of the current row we are on
        int curRow = 0;
        // goingDown indicates the direction we are moving (up or down)
        bool goingDown = false;

        // For each character in the input string,
        for (char c : s) {
            // add the character to the current row
            rows[curRow] += c;
            // If we have reached the top or bottom row, change direction
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            // Update the current row
            curRow += goingDown ? 1 : -1;
        }

        // Combine all the rows into a single string
        string res;
        for (string row : rows) res += row;
        return res;
    }
};
```
<hr>

<br><br>

## 4)  [Permutation in String](https://leetcode.com/problems/permutation-in-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Hash Table` `Two Pointers` `String` `Sliding Window`

### Code


```cpp
class Solution {
public:

    // function that compares two maps, each map represents a frequency array.
    bool equal(unordered_map<char,int>&first, unordered_map<char,int>&second){
        for(char c='a'; c<='z'; c++){
            if(first[c]!=second[c])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // first string is bigger than second string, it is impossible to include all the first in the second.
        if(s1.size()>s2.size())
            return false;

        // carrys the count of each character in the first string
        unordered_map<char,int>first;
        for(auto& c: s1)
            first[c]++;

        // carrys the count of each character in the initial window (windows size = s1.size())
        unordered_map<char,int>second;
        for(int i=0; i<s1.size(); i++)
            second[s2[i]]++;

        // check if the initial window frequency is equal to the first string (s1)
        if(equal(first, second))
            return true;

        // slide the window till we reach the end of s2, updating the second map with each step (adding the next element, and removing the very first element of the previous window)
        for(int i=s1.size(); i<s2.size(); i++)
        {
            second[s2[i]]++;                // add new element to the window
            second[s2[i-s1.size()]]--;      // remove the very first element of the old window

            if(equal(first, second))        // check if window freq == first string freq
                return true;        
        }
        return false;
    }
};

```
<hr>

<br><br>

## 5)  [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Hash Table` `String` `Sliding Window`

### Code


```cpp
class Solution {
public:
    vector<int> findAnagrams(string& s, string& p) {
        // make frequency for string s and string p
        vector < int > freq_s(26), freq_p(26);

        // add all character in string p to the frequency
        for(auto& c : p) freq_p[c - 'a']++;

        // store the indices of the start of the angrams
        vector < int > ans;

        int l = 0, r = 0;
        while(r < s.size()){
            // while r - l smaller than p we will add new characters to the current frequency
            while(r < s.size() && r - l < p.size()) freq_s[s[r++] - 'a']++;
            
            // if the two frequencies are the same so the current window will be an angram 
            if(freq_s == freq_p) ans.push_back(l);

            // remove the current character
            freq_s[s[l++] - 'a']--;
        }

        // the indices of the start of the angrams
        return ans;
    }
};
```

<hr>

<br><br>

## 6)  [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array`

### Code


```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // the shuffled vector 
        vector < int > shuffled_vec;

        // we will devide the vector into two halves and add one element from first one and one element from second one
        for(int i = 0, j = n; i < n; i++, j++)
            shuffled_vec.push_back(nums[i]), shuffled_vec.push_back(nums[j]);

        // the resulted vector
        return shuffled_vec;
    }
};
```

<hr>

<br><br>

## 7)  [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Hash Table` `Sliding Window`

### Code


```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //  the frequency of each type of tree
        map < int, int > freq;

        // two pointers to moves
        int l = 0, r = 0, max_fruits = 0, n = fruits.size();
        
        while(r < n){
            // add the current tree
            freq[fruits[r]]++;

            // check if you have only two types of trees or not
            while(freq.size() > 2){
                // remove the leftmoste tree from the baskets until you have two unique types of trees
                freq[fruits[l]]--;
                
                // if the frequency of this tree becomes zero so let's remove it
                if(freq[fruits[l]] == 0)
                    freq.erase(fruits[l]);
                
                // move from the leftmost tree to it's right tree
                l++;
            }
            
            // update max_fruits can collect with the size of the range
            max_fruits = max(max_fruits, r - l + 1);

            // move the rightmost tree
            r++;
        }

        // maximum number of fruits can be picked
        return max_fruits;
    }
};
```
<hr>

<br><br>

## 8)  [Jump Game II](https://leetcode.com/problems/jump-game-ii/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Dynamic Programming` `Greedy`

### Code


```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector < int > dp(n + 1, 1e9);

        // base case for dp
        dp[n - 1] = 0;
        
        // for each dp[i] calculate minmum move to reach it
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j <= nums[i] && j + i <= n - 1; j++)
                dp[i] = min(dp[i], 1 + dp[i + j]);

        //  the minimum number of jumps
        return dp[0];
    }
};
```

<hr>

<br><br>

## 9)  [Naming a Company](https://leetcode.com/problems/naming-a-company/)

### Difficulty

**${\bf{\color\{red}\{Hard}}}$**

### Related Topic

`Array` `Hash Table` `String` `Bit Manipulation` `Enumeration`

### Code


```cpp
class Solution {
public:
    
    #define sz(x) int(x.size())

    long long distinctNames(vector<string>& ideas) {
        long long disName = 0;

        // adjacent list for each character
        vector < unordered_set < string > > adj(26);
        
        // add each string to the vector of each character
        for (string s : ideas) 
            adj[s[0] - 'a'].insert(s.substr(1));
        
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                // merge the two sets into one set
                unordered_set < string > unique;
                unique.insert(adj[i].begin(), adj[i].end());
                unique.insert(adj[j].begin(), adj[j].end());

                // update the disName
                disName += (sz(adj[i]) - sz(unique)) * (sz(adj[j]) - sz(unique));
            }
        }

        // the answer will be the double of disName
        return disName * 2;
    }
};
```

<hr>

<br><br>

## 10)  [As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Dynamic Programming` `Breadth-First Search` `Matrix`

### Code


```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // vector contains the four direction to loop on them
        vector < pair < int, int > > dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // lets make bfs from each land cell to calculate the minimum distance from each cell of them to water cells
        vector < vector < int > > dist(n, vector < int > (m, 1e9));
        queue < pair < int, int > > bfs;

        // lets add land cells
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1)
                    dist[i][j] = 0, bfs.push({i, j});

        // if there is no land cell
        if(bfs.empty())
            return -1;

        // check if valid cell to add it
        auto is_valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m && !grid[x][y];
        };

        while(!bfs.empty()){
            auto [x, y] = bfs.front();
            bfs.pop();

            for(auto& [dx, dy] : dir){
                int nx = x + dx, ny = y + dy;

                // if the new cell is valid and you can reach it with distance less than its distance so add it to the queue
                if(is_valid(nx, ny) && dist[nx][ny] > dist[x][y] + 1)
                    dist[nx][ny] = dist[x][y] + 1, bfs.push({nx, ny});
            }
        }

        // loop over the distance 2D vector to get the maximum distance for each water cell
        int max_dist = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!grid[i][j])
                    max_dist = max(max_dist, dist[i][j]);

        return max_dist;
    }
};
```
<hr>

<br><br>

## 11)  [Shortest Path with Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Graph` `Breadth-First Search`

### Code


```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector < vector < pair < int, int > > > adj(n);
        vector < vector < int > > path(n, vector < int > (2, -1));
        
        // make the adjacency list each adjacent pair will be the another node and the color of the edge
        for(auto& v : redEdges)
            adj[v[0]].push_back({v[1], 0});
        for(auto v:blueEdges)
            adj[v[0]].push_back({v[1], 1});
        
        // do bfs from 0 to each nodes
        queue < pair < int, int > > bfs;
        bfs.push({0,0});
        bfs.push({0,1});
        path[0] = {0,0};
        
        while(!bfs.empty()){
            // current node and current color
            auto [u, c] = bfs.front(); 
            bfs.pop();
            
            for(auto [v, new_c] : adj[u]){
                // if this edge is the new edge is same colour will the current edge or this state is appears before skip it
                if(path[v][new_c] != -1 || c == new_c) continue;

                // update the path to the new vertex and put it in the queue
                path[v][new_c] = 1 + path[u][c];
                bfs.push({v, new_c});
            }
        }

        // add the minimum path for each vertex
        vector < int > res;
        for(auto& v : path) {
            sort(v.begin(), v.end());
            res.push_back(v[0] != -1 ? v[0] : v[1]);
        }

        return res;
        
    }
};
```

## 12)  [Minimum Fuel Cost to Report to the Capital](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Graph`

### Code


```cpp
class Solution {
public:
    
    #define ceil(n, m) (((n) + (m) - 1) / (m))

    vector < vector < int > > adj;
    vector < int > child;

    long long dfs(int u, int p, int seats){
        long long fuel = 0;
        for(auto& v : adj[u]){
            // to avoid cycling
            if(v == p) continue;

            // dfs on the child of u to get the size of each subtree of them and the answers also
            fuel += dfs(v, u, seats);
            
            // add the subtree size of v to subtree of u
            child[u] += child[v];
        }

        // the fuel used will be the sum of that used in my children and ceil the seats of current subtree
        if(u != 0)
            fuel += ceil(child[u], seats);
        
        return fuel;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        adj = vector < vector < int > > (n);
        child = vector < int > (n, 1);

        // make adjacency list for all nodes
        for(auto& v : roads)
            adj[v[0]].push_back(v[1]), adj[v[1]].push_back(v[0]);

        // dfs from root to get_answers;
        return dfs(0, -1, seats);
    }
};
```
