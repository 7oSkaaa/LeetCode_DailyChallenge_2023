// Author: Ahmed Hossam

class Solution {
public:

    string simplifyPath(string path) {
        // Initialize variables
        int length = path.size();
        string ans;
        stack < int > S;
        int i = 1;
        
        // Loop through the path
        while(i < length){
            // Add a slash to the answer string
            ans += "/";
            
            // Find the next index of '/'
            int next_ind = path.find('/', i);
            
            // If there are no more '/', set next_ind to the end of the path
            if(next_ind == std::string::npos) next_ind = length;
            
            // Get the current directory
            string curr_dir = path.substr(i, next_ind - i);
            
            // If the current directory is empty or '.', remove the last character from the answer string
            if(curr_dir.empty() || curr_dir == ".") ans.pop_back();
            // If the current directory is '..', remove the last directory from the answer string
            else if(curr_dir == ".."){
                if(S.empty()) ans.clear();
                else{
                    int prev_idx = S.top();
                    S.pop();
                    ans = ans.substr(0, prev_idx - 1);
                }
            }
            // Otherwise, add the current directory to the answer string
            else{
                int curr_length = ans.size();
                S.push(curr_length);
                ans += curr_dir;
            }
            
            // Update i to the next index of '/'
            i = next_ind + 1;
        }
        
        // If the answer string is empty, return '/'
        if(ans.empty()) return "/";
        return ans;
    }
};
