//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))
/*
Here if we werent restricted by that sentence "at most k stops. ", we could be able to solve that problem using Dijkstra..
We deal with "Stops" as max levels we can visit so,We may modify BFS to get minimum cost as possible within same level 
*/
class Solution {
public:
  
    struct flight{
        int x,cost,stops;
    }; // Struct for the flight itself , x is label of city , cost -> how much we consumed till reaching that city , stops --> how many stops we did till reaching it

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>v(n+2); //adjacency list for our graph
        
        int costt[n+2]; // to store minimum cost for each reached city
        MemS(costt,-1); // initialize it with -1 as a base state

        for(auto it:flights)
            v[it[0]].push_back({it[1],it[2]}); // simulate the graph into our adjacency list <to,weight>
        
        costt[src] = 0; //the cost to travel from src to src is 0
        flight curr = {src, 0, 0}; //our start is from src city with 0 cost and 0 stops
        
        queue<flight>pq; // queue to implement BFS
        
        pq.push(curr); //push our start

        while(sz(pq)){ // till we finish visiting all nodes we can visit in our graph
           
            curr = pq.front(),pq.pop(); 
            
            if(curr.stops > k) // we don't need to go into further levels "stops" , return current answer
                return costt[dst];
           
            
            for(auto ch:v[curr.x]) // for each negihbour of current node, if it wasn't visited before or we can visit it with less cost than before then update it 
                if(costt[ch.first]==-1 || ch.second + curr.cost < costt[ch.first])
                   costt[ch.first] = ch.second + curr.cost,pq.push({ch.first,costt[ch.first], curr.stops + 1});
        }

        return costt[dst]; //return answer in case we used less stops than k
    }
};
