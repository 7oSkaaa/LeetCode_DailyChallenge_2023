// Author: Mahmoud Aboelsoud

class Solution {
public:
    // initialize the vals vector and edges vector that are given in the problem 
    vector<int> vals;
    vector<vector<int>> edges;

    // initialize the parent vector, set_size vector, max_in_set vector, cnt_max_in_set vector for the union find algorithm
    vector<int> parent, set_size, max_in_set, cnt_max_in_set;

    // initialize the ans variable for the number of good paths
    int ans = 0;

    // union find algorithm

    // find_set function to find the parent of the given node
    int find_set(int v){
        if(v == parent[v]) return v;

        return parent[v] = find_set(parent[v]);
    }

    // union_sets function to union two nodes
    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(set_size[a] < set_size[b])
                swap(a, b);
            parent[b] = a;

            // if the max value in the set of a is less than the max value in the set of b
            if(max_in_set[a] < max_in_set[b]){
                // update the max value in the set of a to the max value in the set of b
                max_in_set[a] = max_in_set[b];
                // update the number of nodes in the set of a to the number of nodes in the set of b which will be the count of the max value in the union of the two sets
                cnt_max_in_set[a] = cnt_max_in_set[b];
            }else if(max_in_set[a] == max_in_set[b]){
                // if the max value in the set of a is equal to the max value in the set of b
                // add the number of new good paths we can get from the union of the two sets to the ans variable 
                ans += cnt_max_in_set[a] * cnt_max_in_set[b];
                // update the count of the max value in the union of the two sets to be the sum of the count in the two sets
                cnt_max_in_set[a] += cnt_max_in_set[b];
            }
            set_size[a] += set_size[b];
        }
    }

    // get_max function to get the max value in the set of the given node
    int get_max(int a){
        return max_in_set[find_set(a)];
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // set the vals vector and edges vector to the given vals vector and edges vector
        this -> vals = vals;
        this -> edges = edges;
        
        // get the number of nodes 
        int n = vals.size();
        
        parent.assign(n, 0), set_size.assign(n, 1), max_in_set.assign(n, 0), cnt_max_in_set.assign(n, 1);

        // set the parent of each node to be itself, the max value in the set of each node to be the value of the node, and the count of the max value in the set of each node to be 1
        for(int i = 0; i < n ; i++){
            parent[i] = i;
            max_in_set[i] = vals[i];
        }

        // sort the edges vector by the max value between the two nodes in the edge
        sort(edges.begin(), edges.end(), [&](vector<int>&p1, vector<int>&p2){
                return max(vals[p1[0]], vals[p1[1]]) < max(vals[p2[0]], vals[p2[1]]);
            }
        );


        // loop on the edges vector
        for(auto&i: edges){
            // union the two nodes in the edge
            union_sets(i[0], i[1]);
        }
        
        // add the number of nodes in the tree to the ans as the path of 1 node is also a good path
        return ans + n;
    }
};
