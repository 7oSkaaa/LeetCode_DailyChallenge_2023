// Author: Mahmoud Aboelsoud

class SummaryRanges {
public:
    // my idea is to use dsu to merge the intervals and keep track of the leaders of each set and the min and max of each set
    // the idea that each number can only be connected to 2 numbers the previous and the next one
    // so we check if the previous and the next number are given to us before and if they are we merge them with the current number
    // and we keep track of the leaders of each set and the min and max of each set
    // and we return the intervals of each leader as the min and max of each set
    

    // initalize vectors to store the parent of each number, the size of each set, the min and max of each set, and a vector to check if the number is given to us or not
    vector<int> parent, set_size, min_in_set, max_in_set, vis;
    // initalize a set to store the leaders of each set
    set<int> leaders;

    // find_set function to find the leader of the set of the given number
    int find_set(int v){
        if(v == parent[v]) return v;

        return parent[v] = find_set(parent[v]);
    }

    // union_sets function to merge the sets of the given numbers
    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(set_size[a] < set_size[b])
                swap(a, b);
            parent[b] = a;
            set_size[a] += set_size[b];
            // update the min and max of the set
            max_in_set[a] = max(max_in_set[a], max_in_set[b]);
            min_in_set[a] = min(min_in_set[a], min_in_set[b]);
        }
    }

    // functions to return the min and max of the set of the given number
    int mx_in_set(int value){
        return max_in_set[find_set(value)];
    }
    
    int mn_in_set(int value){
        return min_in_set[find_set(value)];
    }

    SummaryRanges() {
        // clear the set and assign the parent of each number to itself and the size of each set to 1 and the min and max of each set to the number itself
        leaders.clear();
        parent.assign(1e4 + 2, 0);
        set_size.assign(1e4 + 2, 1);
        min_in_set.assign(1e4 + 2, 0);
        max_in_set.assign(1e4 + 2, 0);
        vis.assign(1e4 + 2, 0);

        for(int i = 0; i <= 1e4; i++)
            parent[i] = i, min_in_set[i] = i, max_in_set[i] = i; 
    }
    
    // addNum function to add the given number
    void addNum(int value) {
        // we mark the number as visited 
        vis[value] = 1;
        // we check if the previous and the next number are given to us before and if they are we merge them with the current number
        // we erase the leader of the set of the previous and the next number from the set of leaders
        // and add the new leader of the set of the current number to the set of leaders
        if(value > 0 && vis[value - 1]){
            leaders.erase(find_set(value - 1));
            union_sets(value, value - 1);
        }

        if(vis[value + 1]){
            leaders.erase(find_set(value + 1));
            union_sets(value, value + 1);
        }

        // we add the leader of the set of the current number to the set of leaders
        leaders.insert(find_set(value));
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        // we return the intervals of each leader as the min and max of each set
        for(auto&i: leaders)
            ans.push_back({mn_in_set(i), mx_in_set(i)});

        return ans;
    }
};
