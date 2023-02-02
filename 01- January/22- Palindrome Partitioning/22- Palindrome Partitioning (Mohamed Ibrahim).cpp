//Author: Mohamed Ibrahim

class Solution {
public:
// Declare a vector to store all possible partitions of the input string
vector<vector<string>> res;

// Declare a vector to store the current partitioning
vector<string> temp;

// Function to check if a substring is a palindrome
bool isPalindrome(string s) {
    // Initialize pointers to the first and last character of the substring
    int left = 0, right = s.size() - 1;
    // Compare the characters from the start and end of the substring
    // If they are not equal, return false
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    // If all characters are equal, return true
    return true;
}

// Recursive function to find all possible partitions of the input string
void dfs(string s, int start) {
    // Base case: if the start pointer has reached the end of the string,
    // push the current partitioning to the result vector and return
    if (start == s.size()) {
        res.push_back(temp);
        return;
    }
    // Iterate through all substrings starting from the current start pointer
    for (int i = start; i < s.size(); i++) {
        // Check if the current substring is a palindrome
        if (isPalindrome(s.substr(start, i - start + 1))) {
            // If it is, add it to the current partitioning
            temp.push_back(s.substr(start, i - start + 1));
            // Recursively call the function with the updated partitioning
            // and the next start pointer
            dfs(s, i + 1);
            // Backtrack by removing the last element from the current partitioning
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    // Call the dfs function with the input string and the initial start pointer
    dfs(s, 0);
    return res;
}
};