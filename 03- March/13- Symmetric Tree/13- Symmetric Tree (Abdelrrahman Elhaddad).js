// Author: Abdelrrahman Elhaddad

/*
- Intuition:
    To compare the left branch and the right branch we have to traverse both branches but in mirror way (like if we traversing the right branch entering the right node of each node first, then entering the left node we shall do the opposie while treversing left branch by entering the left node of each node first, then entering the right node) and store their elments, and compare branches values at the end.

- Approach:
    1- Initialize two vectors (rightBranch and leftBranch) to store branches values.
    2- Traverse right branch by entering the right node of each node first, then entering left node.
    3- Traverse left branch by entering the left node of each node first, then entering right node.
    4- Check if the size of rightBranch and leftBranch does not match, return false.
    5- If sizes match, compare each two values with the same index. If two elements does not match return false.
    6- If did not find any dismatchs in the loop then return true.

- Complexity:
    Time complexity: O(n)
    Space complexity: O(2∗n)
*/

function isSymmetric(root) {
    let rightBranch = [], leftBranch = [];

    // Function to traverse the right branch and store its values
    function storeRightValues(node) {
        if (!node) {
            rightBranch.push(1000);
            return;
        }

        rightBranch.push(node.val);

        storeRightValues(node.right); storeRightValues(node.left);
    }

    // Function to traverse the left branch and store its values
    function storeLeftValues(node) {
        if (!node) {
            leftBranch.push(1000);
            return;
        }

        leftBranch.push(node.val);

        storeLeftValues(node.left);
        storeLeftValues(node.right);
    }

    storeRightValues(root?.right);
    storeLeftValues(root?.left);

    if (rightBranch.length != leftBranch.length)
        return false;

    for (let i = 0; i < rightBranch.length; i++)
        if (rightBranch[i] != leftBranch[i])
            return false;

    return true;
};