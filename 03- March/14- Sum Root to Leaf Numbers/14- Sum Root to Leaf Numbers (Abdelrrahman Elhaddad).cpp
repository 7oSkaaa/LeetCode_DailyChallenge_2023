//Author: Abdelrrahman Elhaddad

/*
# Intuition
    If I want to return the total sum of all root-to-leaf numbers, then I will have to traverse through the tree from the root node to the leaf node.
    We are going to use DFS for that. And if I want to add a new digit to the right of an existing number,
    I can do it by multiplying the existing number by 10 that is going to create a new digit to the right,
    then adding the number that I wish to add in the new digit.

# Approach
    1. Initialize sum global variable
    2. Calling `rec` in the `sumNumbers`
    3. Passing it to the `root` to start traversing from it and the num as `0` so it does not affect my future operations in the traversal
    4. Every time I enter a node I add its value to my number
    5. Then Checking whether it is a leaf node or it does have childs
    6. If it is a leaf node, I add its values to the sum and return back
    7. If it does have childs I continue traversing

# Complexity
    - Time complexity: O(n)
    - Space complexity: O(1)
*/


class Solution {
public:
    // Initializing a global variable to store the sum in it
    // It has to be global to be used in both functions without passing it
    int sum = 0;

    // The function that should do all the recursion work by traversing all the nodes (DFS)
    void rec(TreeNode* node, int num){
        // Adding a new digit to the number by multiplying it by 10 and adding the new number in the new digit
        // ex. 3 -> 30 -> 32
        num *= 10;
        num += node -> val;

        // Checking if the left node exists, If so enter it
        if (node -> left)
            rec(node -> left, num);

        // Checking if the right node exists, If so enter it
        if (node -> right)
            rec(node -> right, num);

        // If neither right nor left node exists that means that we are currently in a leaf node, so we will add the currrent num to the global sum variable
        if (!(node -> right) && !(node -> left))
            sum += num;
    }

    int sumNumbers(TreeNode* root) {
        // Calling the recursion function
        rec(root, 0);

        // Returning the sum variable after being updated by the recursion function
        return sum;
    }
};
