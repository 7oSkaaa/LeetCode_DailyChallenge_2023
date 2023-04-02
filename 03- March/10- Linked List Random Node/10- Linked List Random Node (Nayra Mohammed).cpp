//Author: Nayra Mohammed

#define sz(s) (int(s.size())) 
class Solution {
public:
    
    unordered_map<int,int>mp;
    Solution(ListNode* head) {
        
        int id = 0; // to give each node an unique id
        
        while(head) // traverse through linked list ,for each node store its value in our hash map with respect to 'id'
            mp[id++]=head->val,head=head->next;
    }
    
    int getRandom() {
        
        return mp[rand()%sz(mp)]; //using rand func in that way ,it'll return an id in range of [0,sz(mp)-1],so we just return the value stored in such one
    }
};
