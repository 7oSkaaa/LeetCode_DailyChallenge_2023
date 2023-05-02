// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the number of edges that we can remove to make the graph fully traversable
    // which mean we need the minimum number of edges to connect to make the graph fully traversable by Alice and Bob
    // we can use DSU to solve this problem 
    // we can make two graphs one for Alice and one for Bob
    // we need to find the minimum number of edges used in both graphs to make each graph connected
    // then we can remove the edges that are not used in both graphs
    // we can use the third type of edges to connect the nodes in both graphs
    // then we can check the needed number of edges to make both graphs connected from the other two types of edges


    // DSU implementation
    struct DSU{

        vector<int> parent, set_size;

        DSU(int n){
            parent.assign(n + 1, 0);
            set_size.assign(n + 1, 1);

            for(int i = 1; i <= n; i++)
                parent[i] = i;
        }

        int find_set(int v){
            if(v == parent[v]) return v;

            return parent[v] = find_set(parent[v]);
        }

        void union_sets(int a, int b){
            a = find_set(a);
            b = find_set(b);
            if(a != b){
                if(set_size[a] < set_size[b])
                    swap(a, b);
                parent[b] = a;
                set_size[a] += set_size[b];
            }
        }

        bool same_set(int a, int b){
            a = find_set(a);
            b = find_set(b);

            return a == b;
        }
    };


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // we make 2 DSU one for Alice and one for Bob
        DSU dsu1(n), dsu2(n);
        
        // cnt: number of edges that is required to make each of the 2 graphs connected
        int cnt = 0;

        // we can use the third type of edges to connect the nodes in both graphs
        for(auto&i: edges){
            // if the edge is of type 3 and the nodes are not connected in both graphs
            if(i[0] == 3 && !dsu1.same_set(i[1], i[2])){
                // we can use this edge to connect the nodes in both graphs
                // we increase the number of required edges by 1
                cnt++;
                // we connect the nodes in both graphs
                dsu1.union_sets(i[1], i[2]);
                dsu2.union_sets(i[1], i[2]);
            }
        }

        // we check the needed number of edges to make both graphs connected from the other two types of edges
        for(auto&i: edges){
            // if the edge is of type 1 and the nodes are not connected in Alice's graph
            if(i[0] == 1 && !dsu1.same_set(i[1], i[2])){
                // we can use this edge to connect the nodes in Alice's graph
                dsu1.union_sets(i[1], i[2]);
                // we increase the number of required edges by 1
                cnt++;
            }
            // if the edge is of type 2 and the nodes are not connected in Bob's graph
            else if(i[0] == 2 && !dsu2.same_set(i[1], i[2])){
                // we can use this edge to connect the nodes in Bob's graph
                dsu2.union_sets(i[1], i[2]);
                // we increase the number of required edges by 1
                cnt++;
            }
        }

        // then we check if all nodes in the given graph are connected in both graphs
        // we do that by checking if the number of nodes in the set of the first node is equal to the number of nodes in the graph
        // if not then we return -1
        if(dsu1.set_size[dsu1.find_set(1)] != n || dsu2.set_size[dsu2.find_set(1)] != n) return -1;
        
        // else we return the number of edges that we can remove to make the graph fully traversable
        return edges.size() - cnt;
    }
};
