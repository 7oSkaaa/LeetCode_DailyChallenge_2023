// author : Ahmed Zedan
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int>nodes; // store value of nodes in linked list 
    Solution(ListNode* head) {
        ListNode *tmp ; 
        while(tmp){
            nodes.push_back(tmp->val) ; 
            tmp = tmp->next ; 
        }
    }
    
    int getRandom() {
        int n = nodes.size() ; // number of nodes
        return nodes[rand()%n] ; // use rand() function to return intger number 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */