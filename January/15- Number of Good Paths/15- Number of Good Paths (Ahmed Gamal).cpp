// Author: Ahmed Gamal

class Solution {
public:

    // to solve this problem, we need to look at the requirements of the problem from a different perspective
    // the problem is asking us to find the number of paths that start and end at nodes with the same value with no greater value in between
    // so, the greater values will act as break points for the paths of smaller values
    // to overcome this problem, we want to calculate the answer for the graph partially (without adding the edges with the greater values)
    // we will build the graph partially, phase by phase, and we will calculate the answer for each phase
    // each phase will be the answer for the graph without the edges with the greater values than the maximum value in the current phase
    // for example, if the maximum value in the current phase is 5, then we will calculate the answer for the graph without the edges with the greater values than 5

    // we want to sort the edges in descending order of the maximum value between the two nodes of the edge in order to use the edges with the greater values in the last phases
    // we want to have all the values in the graph in a sorted array to iterate over them and use them as the maximum value in each phase
    // in each phase, we will use only the edges that connect nodes with values less than or equal to the maximum value in the current phase
    
    // the answer for one component is the number of paths between any two nodes in the component (the number of pairs of nodes in the component because this is a tree and there are no more than one path between any two nodes)
    // so each pair of nodes in the component will add 1 to the answer for the component
    // we can use a DSU (Disjoint Set Union) data structure to group the nodes in the same component
    // we will use a map to store the number of nodes in each component

    // how to store the number of nodes in each component? 
    // if we join two components, the number of nodes in the new component will be the sum of the number of nodes in the two components + 1 (the new node (if it the joined node's value is equal to the maximum value in the current phase))
    // so we will store the number of nodes in each component in the map
    // before joining two components, we will check if the joined node's value is equal to the maximum value in the current phase and store the current frequency of the maximum value in the two components
    // we will set the frequency of the maximum value in the joined components to 0
    // then we will join the two components
    // after joining the two components, we will set the frequency of the maximum value in the joined component to the sum of the frequency of the maximum value in the two components
    // we will add the number of pairs of nodes in the joined component to the answer for the current phase
    // we will repeat this process until we reach the last phase (the phase with the minimum value in the graph)

    // we will add n to the final answer because each node is a path by itself

    // the complexity of this solution is O(n log n) because we sort the edges and the values in the graph

    #define all(v) v.begin(), v.end()

    // Disjoint Set Union data structure
    struct dsu{
        vector<int> p, rank;

        explicit dsu(int size){
            p.resize(size + 1);
            rank.resize(size + 1);

            iota(all(p), 0);
        }

        int get(int x){
            return p[x] = x == p[x] ? x : get(p[x]);
        }

        void join(int u, int v){
            u = get(u), v = get(v);

            if(u == v)
                return;

            if(rank[u] == rank[v])
                rank[u]++;

            if(rank[u] > rank[v])
                p[v] = u;
            else
                p[u] = v;
        }
    };

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // sort the edges in descending order of the maximum value between the two nodes of the edge
        sort(all(edges), [&](vector<int>& a, vector<int>& b){
            return max(vals[a.front()], vals[a.back()]) > max(vals[b.front()], vals[b.back()]);
        });

        // sort the values in the graph in ascending order
        // un_vals will contain the values in the graph without duplicates (un: unique, vals: values)
        auto un_vals = vals;
        sort(all(un_vals));
        // remove the duplicates from un_vals
        un_vals.erase(unique(all(un_vals)), un_vals.end());

        // the answer for the graph (initially, the answer is the number of nodes in the graph)
        int ans = int(vals.size());
        // the DSU data structure to group the nodes in the same component
        dsu d(ans);
        // iterate over the values in the graph in ascending order
        for(auto& i : un_vals){
            // the map to store the number of nodes with maximum value in each component
            map<int, int> freq;

            // iterate over the edges in the graph in descending order of the maximum value between the two nodes of the edge
            while(not edges.empty()){
                // the two nodes of the edge
                int u = edges.back().front(), v = edges.back().back();
                // if the maximum value between the two nodes of the edge is greater than the current value, then we will break the loop (we can't use the edges with the greater values in the current phase)
                if(max(vals[u], vals[v]) > i)
                    break;
                // remove the used edge
                edges.pop_back();

                // the frequency of the maximum value in the two components before joining them
                // 1 if the joined node's value is equal to the maximum value in the current phase
                // 0 otherwise
                int old_u = max(i == vals[u] ? 1 : 0, freq[d.get(u)]);
                int old_v = max(i == vals[v] ? 1 : 0, freq[d.get(v)]);

                // set the frequency of the maximum value in the two components to 0
                freq[d.get(u)] = freq[d.get(v)] = 0;
                // join the two components
                d.join(u, v);
                // set the frequency of the maximum value in the joined component to the sum of the frequency of the maximum value in the two components
                freq[d.get(u)] = old_v + old_u;
            }
            // add the number of pairs of nodes with maximum value in each component to the answer for the current phase
            for(auto& [x, y] : freq){
                ans += y * (y - 1) / 2;
            }
        }

        // return the answer for the graph
        return ans;
    }
};