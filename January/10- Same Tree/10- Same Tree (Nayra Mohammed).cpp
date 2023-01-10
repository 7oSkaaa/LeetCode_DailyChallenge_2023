//Author: Nayra Mohammed

class Solution {

  public:
  
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if we reached nodes both of them are null then we consider they are same
        if(p == q && q == nullptr) 
            return 1;
     
        //having a one node with NULL value and the other exists ,or both have different values from each other then for sure they are different! 
        if(p==nullptr || q==nullptr ||p->val != q->val) return 0;   
        
        //reaching here means current node from the first tree equals current node from the second tree
        bool ok = 1; 
        
        //here we go to the left and right childs of both nodes to check their similarity
        ok &=isSameTree(p->left,q->left); 
        ok &=isSameTree(p->right,q->right); // we use AND_Bitwise for the fact (1 & 1 & 1 = 1) otherwise 0
        
        return ok; // return answer.
    }
};
