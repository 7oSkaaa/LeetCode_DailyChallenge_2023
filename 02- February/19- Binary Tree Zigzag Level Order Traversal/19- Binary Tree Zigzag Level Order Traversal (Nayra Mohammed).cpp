// Author : Nayra Mohammed

#define sz(s) (int(s.size()))

class Solution
{
public:

    /*
        - We gonna use BFS to traverse through th graph level by level.
        - Starting from root as level 0, for every odd level we gonna store it's values
          from right node to left node in that level Otherwise,We store from left to right.      

    */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root) // We have an empty tree so we return nothing.
            return {};

        vector<vector<int>> ans; // To store the final answer
        
        bool rev = 1; // To track whether in current level we'll store the values from right to left or not

        queue<TreeNode *> q;//queue to implement BFS algo
        q.push(root);//push the first level in our tree
        
        while (sz(q))
        {
            vector<int> curr; //to store the values of current level
            rev ^= 1; // reverse the state of rev to become 0 in even levels otherwise, 1
        
            int n = sz(q); //to store level's size
        
            while (n--)
            {
                //for each node of current level we gonna store it's values 
                root = q.front(), q.pop();
                
                curr.push_back(root->val);
                
                //and pushes it's childs "if they exist" in the queue as the upcoming level
                if (root->left)
                    q.push(root->left);

                if (root->right)
                    q.push(root->right);
            }
        
            if (rev)//if rev = 1 "we are in an odd level",then we reverse the order of curr 
                reverse(curr.begin(), curr.end());
            
            //push current level's values into our answer
            ans.push_back(curr);
        }

        return ans;
    }
};
