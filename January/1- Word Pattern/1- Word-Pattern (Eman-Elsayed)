//Author : Eman Elsayed

class Solution {
public:
    bool wordPattern(string pattern, string s) {
    // map for storing indices for each character
       map<char , vector<int>>Idx;
       // loop on characters pattern string and push their indices 
       for(int i=0;i<pattern.size() ;i++){
           Idx[pattern[i]].push_back(i);
       }
       // use stringstream to read from string as if it were a stream like cin
       // to know more about string stream from https://www.geeksforgeeks.org/stringstream-c-applications/
       stringstream ss(s);
       // A string to store the word on each iteration.
       string word;
       // Create vector to hold our words
       vector<string>tmp;
       while(ss >> word){
        // ignore spaces and manipulate the string as seperate words
         // Finally push it.
           tmp.push_back(word);
       }
       // check if they are not the same size
       if(tmp.size() != pattern.size()){
           return false;
       }
       //create set comp to store unique string that appears for each character
       set<string>comp;
       int cnt =0; // counter to know character-no that appear in pattern string 
       for(auto &i:Idx){
           set<string>st;
           cnt++;
           // iterate on indices for each character and insert string value in set to chech after that 
           for(int j = 0 ; j < i.second.size();j++){
               st.insert(tmp[i.second[j]]);
           }
           // here check if string value for the same char are equal or not
           if(st.size() != 1){
               return false;
           }
           // if is equal we put the only string at comp to compare finally 
           // using this to avoid this case 
           // Ex : pattern = abba s = "dog dog dog dog"
           comp.insert(*st.begin());
       }
        return comp.size() == cnt;
    }
};
