// Author : Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution {
public:
    map<int, int>mp1; // for distances from node1 to all other nodes
    map<int, int>mp2; // for distances from node2 to all other nodes
  
    void BFS1(vector<int>&v,int st){
        queue<int>q;
        
        q.push(st); //push our node "node1", where we gonna state traversing though it
        
        mp1[st] = 0; //set distance from the node to itself to 0
        
        while(sz(q)){
         
            st = q.front(),q.pop(); //get node from current level
          
            // if there exists a neighboor and  it wasn't visited before then we add it to queue as a new node to next level
            if(v[st] != -1 && mp1.find(v[st]) == mp1.end())  
                q.push(v[st]),mp1[v[st]] = mp1[st] + 1;
        }
    }

    int BFS2(vector<int>&v,int st){
        
        int mn = 1e9, ans = -1; // mn -> to compare between the maxs of node1 and node2 to a specific node x
                                // ans ->  to store the minimum node needed. our answer
        
        //Here we do same steps as we did with node1
        queue<int>q;
        q.push(st);
        mp2[st] = 0;
       
        while(sz(q)){
            st = q.front(),q.pop();
          
            if(mp1.find(st) != mp1.end()) //if current node was visited by node1
            {
            
                if(max(mp2[st],mp1[st]) < mn) // in case the max between the distance from node1 and node2 to current node is less than our base_mn 
                    mn = max(mp2[st], mp1[st]), ans = st; //update mn and consider current node as our answer
                else if(max(mp1[st],mp2[st])==mn) // in case of similarity then we need to take the minimum labeled node
                    ans = min(ans, st);    
            }
  
            if(v[st] != -1 && mp2.find(v[st]) == mp2.end())
                q.push(v[st]),mp2[v[st]] = mp2[st] + 1;
        }

        return ans; //return the requested answer
    }
  
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        BFS1(edges,node1); // to calculate the distance from node1 to all other nodes
    
        return BFS2(edges,node2); // to calculate the distance from node2 to all other nodes  and get the requested answer      
    }
};
