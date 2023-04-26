# LeetCode Daily Challenge Problems for February

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
1. **[Count Odd Numbers in an Interval Range](#13--count-odd-numbers-in-an-interval-range)**
1. **[Add Binary](#14--add-binary)**
1. **[Add to Array-Form of Integer](#15--add-to-array-form-of-integer)**
1. **[Maximum Depth of Binary Tree](#16--maximum-depth-of-binary-tree)**
1. **[Minimum Distance Between BST Nodes](#17--minimum-distance-between-bst-nodes)**
1. **[Invert Binary Tree](#18--invert-binary-tree)**
1. **[Binary Tree Zigzag Level Order Traversal](#19--binary-tree-zigzag-level-order-traversal)**
1. **[Search Insert Position](#20--search-insert-position)**
1. **[Single Element in a Sorted Array](#21--single-element-in-a-sorted-array)**
1. **[Capacity To Ship Packages Within D Days](#22--capacity-to-ship-packages-within-d-days)**
1. **[IPO](#23--ipo)**
1. **[Minimize Deviation in Array](#24--minimize-deviation-in-array)**
1. **[Best Time to Buy and Sell Stock](#25--best-time-to-buy-and-sell-stock)**
1. **[Edit Distance](#26--edit-distance)**
1. **[Construct Quad Tree](#27--construct-quad-tree)**
1. **[Find Duplicate Subtrees](#28--find-duplicate-subtrees)**

<hr>

<br><br>

## 1)  [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

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

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

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

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

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

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

<hr>

<br><br>


## 12)  [Minimum Fuel Cost to Report to the Capital](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

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

<hr>

<br><br>


## 13)  [Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Math`

### Code


```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        // count odd number in range from 1 to x
        auto count_odd = [&](int x){
            return (x + 1) / 2;
        };

        // number of odd from l to r will be number of odd from [1 to r] - number of odd from [1 to l - 1]
        return count_odd(high) - count_odd(low - 1);
    }
};
```
<hr>

<br><br>


## 14)  [Add Binary](https://leetcode.com/problems/add-binary/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Math` `String` `Bit Manipulation` `Simulation`

### Code


```cpp
class Solution {
public:

    string addBinary(string& a, string& b) {
        string sum;
        // iterate over the two strings from the end
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        // while we have not reached the beginning of the strings
        while(~i || ~j){
            // get the current bit and add the carry to it
            int current_bit = carry;

            // if the index is valid, add the bit to the current bit
            if(~i)
                current_bit += a[i--] - '0';
            
            // if the index is valid, add the bit to the current bit
            if(~j)
                current_bit += b[j--] - '0';
            
            // add the current bit to the sum
            sum += (current_bit % 2) + '0';

            // update the carry for the next iteration
            carry = current_bit / 2;
        }

        // if there is a carry left, add it to the sum
        if(carry)
            sum += '1';

        // reverse the sum to get the correct order
        reverse(sum.begin(), sum.end());

        // return the sum
        return sum;
    }
};
```
<hr>

<br><br>


## 15)  [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Math` `Array`

### Code


```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // we turn the two numbers to strings for the ease of manipulation
        // then we sum the two numbers from the right to the left
        // and we keep track of the carry
        // and at each point we store the sum % 10 in the result
        // and the carry is the sum / 10

        string s1 = "";
        string s2 = to_string(k);
        for(auto&i: num)
            s1 += i + '0';

        // i is the index of the last digit in s1, j is the index of the last digit in s2, carry is the carry
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
        string res = "";

        // while we haven't reached the end of both s1, s2, and carry is not 0
        while(i >= 0 || j >= 0 || carry > 0){
            // if we haven't reached the end of s1, we add the digit to the carry
            if(i >= 0)
                carry += s1[i--] - '0';

            // if we haven't reached the end of s2, we add the digit to the carry
            if(j >= 0)
                carry += s2[j--] - '0';

            // we add the carry % 10 to the result
            res += (carry % 10) + '0';
            // we update the carry to be the carry / 10
            carry /= 10;
        }

        // we turn the result to a vector of integers and reverse it because we added the digits from the right to the left but we stored them from the left to the right
        vector<int> ans(res.size());
        for(i = 0, j = res.size() - 1; i < ans.size(); i++, j--)
            ans[i] = res[j] - '0';

        return ans;
    }
};
```
<hr>

<br><br>


## 16)  [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if the root is null i will return 0
        // otherwise i will return 1 + max depth of my left and right children depth
        return (!root ? 0 : 1 + max(maxDepth(root -> right), maxDepth(root -> left)));
    }
};
```

<hr>

<br><br>

## 17)  [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree` `Binary Search Tree`

### Code


```cpp
class Solution {
public:

    // get values of the tree
    vector < int > values;

    // Left -> Root -> Right
    void Inorder(TreeNode* root){
        if(!root) return;
        Inorder(root -> left);
        values.push_back(root -> val);
        Inorder(root -> right);
    }

    int minDiffInBST(TreeNode* root) {
        // lets make Inorder traverse to get the tree sorted in increasing order
        Inorder(root);

        // let get the min_diff between any two adjacent numbers
        int min_diff = 1e9;
        for(int i = 1; i < values.size(); i++)
            min_diff = min(min_diff, values[i] - values[i - 1]);

        return min_diff;
    }
};
```

## 18)  [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    
    void invert(TreeNode* root){
        // if the root is null so do nothing and return
        if(!root) return;
        
        // swap the left subtree with the right subtree
        swap(root -> right, root -> left);
        
        // swap each subtrees in the right subtree
        invert(root -> right);
        
        // swap eaxh subtrees in the left subtree
        invert(root -> left);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
```

<hr>

<br><br>


## 19)  [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Tree` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // if the root is empty
        if(!root) return {};

        // to store the nodes in each level in zigzag order
        vector < vector < int > > nodes;
        
        // make bfs on the tree
        queue < TreeNode* > bfs;
    
        // add root to start from it
        bfs.push(root);

        // add the two children
        auto add_children = [&](TreeNode* node){
            // if the child is available so add it
            if(node -> left)
                bfs.push(node -> left);
            if(node -> right)
                bfs.push(node -> right);
        };

        // to know the current level
        int level = 0;

        while(!bfs.empty()){
            int sz = bfs.size();
            
            // store the nodes of the current level
            vector < int > current_level_nodes;

            // iterate on the current level nodes
            while(sz--){
                auto node = bfs.front();
                bfs.pop();
                
                // add the current node val to the vector
                current_level_nodes.push_back(node -> val);

                // add the childrens of node
                add_children(node);
            }

            // zigzag order will be if the current level is odd and order will be normal
            // otherwise the order will be reversed
            if(level & 1)
                reverse(current_level_nodes.begin(), current_level_nodes.end());

            nodes.push_back(current_level_nodes);        

            // move to the current level
            level++;
        }

        return nodes;
    }
};
```

<hr>

<br><br>

## 20)  [Search Insert Position](https://leetcode.com/problems/search-insert-position/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // get the index of the first element greater than or equal target
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```

<hr>

<br><br>

## 21)  [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // a ^ a = 0 
        // so each element will enter twice will be zero so the remaining answer will be the number that appears odd times
        int xr = 0;
        for(auto& i : nums)
            xr ^= i;
        return xr;
    }
};
```
<hr>

<br><br>

## 22)  [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        // functions is_good to check the current capacity
        auto is_good = [&](int max_cap){
            // days to ship all weights and the current capacity
            int days_to_use = 1, curr_cap = 0;
            for(auto& w : weights){
                // if any wieght is greater than max_cap this max_cap isn't good
                if(w > max_cap) return false;

                // add current weight to current cap
                curr_cap += w;

                // if the current cap is greater than max_cap we will use another day to ship it
                if(curr_cap > max_cap)
                    curr_cap = w, days_to_use++;
            }

            // current_max_cap will be good if the number of days to move all weights smaller than number of allowed days
            return days_to_use <= days;
        };

        // we will make binary search to get the maximum capacity
        int l = 1, r = 1e9, ans = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }
        // the answer will be the minimum good capacity to use
        return ans;
    }
};
```

<hr>

<br><br>

## 23)  [IPO](https://leetcode.com/problems/ipo/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

### Code


```cpp
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // make vector of indices to sort it
        vector < int > Idx(n);
        
        // make the vector 0 ... n - 1
        iota(Idx.begin(), Idx.end(), 0);
        
        // We sort the projects by their minimum capital required in ascending order because we want to consider the projects that we can afford with our current capital. 
        // By iterating over the sorted projects, we can ensure that we only consider the projects that have a minimum capital requirement less than or equal to our current capital.
        sort(Idx.begin(), Idx.end(), [&](int i, int j){
            return capital[i] < capital[j] || (capital[i] == capital[j] && profits[i] < profits[j]);
        });
        
        int i = 0;
        priority_queue < int > maximizeCapital;
        while (k--) {
            //The condition capital[Idx[i]] <= w checks if the minimum capital requirement of the next project is less than or equal to our current capital w. If this condition is true, we can add the project to the priority queue because we have enough capital to start the project.
            //We use this condition to ensure that we only add the available projects that we can afford to the priority queue. By checking the minimum capital requirement of the next project before adding it to the priority queue, we can avoid adding projects that we cannot afford, and we can focus on selecting the most profitable project that we can afford with our current capital.
            while (i < n && capital[Idx[i]] <= w) 
                maximizeCapital.push(profits[Idx[i++]]);

            if (maximizeCapital.empty()) break;

            w += maximizeCapital.top();
            maximizeCapital.pop();
        }

        return w;
    }
};
```


<hr>

<br><br>

## 24)  [Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Greedy` `Ordered Set` `Heap (Priority Queue)`

### Code


```cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue < int > pq;
        int minval = INT_MAX;
        
        // make all elements even
        for(auto& i : nums){

            // if the number is odd multiply it by 2 to be even
            if(i & 1) i *= 2;

            // get the minimum value after make all element even
            minval = min(minval, i);

            // add the element in the pq
            pq.push(i);
        }

        // to get the minimum diff
        int diff = INT_MAX;

        // while the first max element in the pq is even
        while(!pq.empty() && pq.top() % 2 == 0){
            // get the max value and remove it from the pq
            int maxval = pq.top();
            pq.pop();

            // update the min diff with min value and max value
            diff = min(diff,maxval - minval);

            // update the min val by the new value of the element
            minval = min(minval, maxval / 2);

            // add new value of the element
            pq.push(maxval / 2);
        }

        // update the minimum diff with max odd element with the min val
        return min(diff, pq.top() - minval);
    }
};
```

<hr>

<br><br>

## 25)  [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        // make vector prices in increasing order to get the max price after current
        vector < int > sorted(prices.size());
        sorted.back() = prices.back();
        for(int i = prices.size() - 2; i >= 0; i--)
            sorted[i] = max(sorted[i + 1], prices[i]);

        // the best profit will be max value after current - current
        int Max = INT_MIN;
        for(int i = 0; i < prices.size(); i++)
            Max = max(Max, sorted[i] - prices[i]);
        return Max;
    }
};

```
<hr>

<br><br>

## 26)  [Edit Distance](https://leetcode.com/problems/edit-distance/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`String` `Dynamic Programming`

### Code


```cpp
class Solution {
    int n,m, memo[505][505];
    string s, t;

public:

    int dp (int i, int j){
        if (j == m) return n-i; // Delete all remain characters in string s
        if (i == n) return m-j; // Insert all remain characters in string t to string s

        int& ans = memo[i][j];
        if (~ans) return ans;

        if (s[i] == t[j]) ans = dp(i+1, j+1);
        else {
            ans = 1 + dp(i+1, j); // Delete
            ans = min(ans, 1 + dp(i, j+1)); // Insert
            ans = min(ans, 1 + dp(i+1, j+1)); // Replace
        }

        return ans;
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        s = word1, t = word2;

        for (int i = 0; i < n + 5; i++)
            for (int j = 0; j < m + 5; j++) 
                memo[i][j] = -1;

        return dp(0, 0);
    }
};
```
<hr>

<br><br>

## 27)  [Construct Quad Tree](https://leetcode.com/problems/construct-quad-tree/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Divide and Conquer` `Tree` `Matrix`

### Code


```cpp
class Solution {
public:
    // Checks if all elements within a sub-grid of size n x n
    // starting from position (x, y) in the grid have the same value.
    bool checkvalue(vector<vector<int>>& grid, int x, int y, int n){
        int m = n, val = grid[x][y];
        for(int i = x; i < x + n; i++){
            for(int j = y; j < y + n; j++){
                if(grid[i][j] != val){
                    return false;
                }
            }
        }
        return true;
    }
    
    // Recursively constructs a Quadtree for the input grid.
    void buildQuad(vector<vector<int>>& grid, Node* root, int x, int y, int n){
        // If all elements in the current sub-grid have the same value,
        // mark the current node as a leaf and set its val to the common value.
        if(checkvalue(grid, x, y, n)){
            root->isLeaf = true;
            root->val = grid[x][y];
        }
        // If the elements in the current sub-grid have different values,
        // mark the current node as an internal node and recursively construct
        // its four child nodes.
        else{
            root->isLeaf = false;
            root->val = 1;  // Doesn't matter, since it's an internal node.
            // Construct the top-left child node.
            root->topLeft = new Node();
            buildQuad(grid, root->topLeft, x, y, n/2);
            // Construct the top-right child node.
            root->topRight = new Node();
            buildQuad(grid, root->topRight, x, y + n/2, n/2);
            // Construct the bottom-left child node.
            root->bottomLeft = new Node();
            buildQuad(grid, root->bottomLeft, x + n/2, y, n/2);
            // Construct the bottom-right child node.
            root->bottomRight = new Node();
            buildQuad(grid, root->bottomRight, x + n/2, y + n/2, n/2);
        }
    }
    
    // Constructs the Quadtree for the input grid and returns the root node.
    Node* construct(vector<vector<int>>& grid) {
        Node* root = new Node();
        int n = grid.size();  // Assume the grid is square.
        buildQuad(grid, root, 0, 0, n);  // Start building the Quadtree from the root node.
        return root;
    }
};
```
<hr>

<br><br>


## 28)  [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `Tree` `Depth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    string postOrder(TreeNode* root, unordered_map<string, int>& subtree_hash, vector<TreeNode*>& result) {
        // null node
        if(!root)
            return "#";
        
        // Get the traversal hash for the left and right subtrees
        string left_hash = postOrder(root -> left, subtree_hash, result);
        string right_hash = postOrder(root -> right, subtree_hash, result);
        
        // Hash string for the current subtree rooted at 'root'
        // If we do left + curr + right, then we can have same pattern for this pattern:
        /*
                       0
                      / \
         [#,0,#,0,#] 0   0 [#,0,#,0,#]
                    /     \
          [#,0,#]  0       0 [#,0,#]
          
          That's why we need either preorder or postorder in subtree path pattern
        */
        string subtree = left_hash + "," + right_hash + "," + to_string(root->val);
        
        // check if the same subtree path was seen before or not
        // If seen before and this is the second time seen, then only add to result
        // don't add after second time since that would be redundant
        if(subtree_hash.count(subtree) && subtree_hash[subtree] == 1)
            result.emplace_back(root);
        
        ++subtree_hash[subtree];
        return subtree;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // <subtree_traversal_path, no. of nodes to have that in their tree with them as root>
        unordered_map < string, int > subtree_hash;
        vector < TreeNode* > result;
        
        postOrder(root, subtree_hash, result);
        return result;
    }
};
```
