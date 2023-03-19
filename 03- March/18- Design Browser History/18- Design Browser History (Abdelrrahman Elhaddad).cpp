//Author: Abdelrrahman Elhaddad

class BrowserHistory {
public:
    vector<string> history;  // To store visited pages
    int curr;  // To determine which page being displayed now

  
    BrowserHistory(string homepage) {
        history = {homepage}; // Push homepage to history vector
        curr = 0; // Currently displaying page with index 0 in history vector
    }

  
    void visit(string url) { // Time Complexity: O(n)
      
      /* If the current displaying page is not the last in the history vector,
       Then we will need to remove all the pages after the current to be able to visit the new page */
        if (curr != history.size() - 1) {
          // Popping pages until current page be the last in the history
            while (history.size() - 1 != curr)
                history.pop_back();
        }
        
      /* After making current page the last in the history vector,
      we will push the new page and increment curr by 1 so it points to the new page */
        history.emplace_back(url);
        curr++;
    }

  
    string back(int steps) { // Time Complexity: O(1)
      
      // If (curr - steps) is less than zero, That means that we will display the first page [index 0]
        if (curr - steps < 0) {
            curr = 0;
            return history[0]; }
          
      // Otherwise we will display the desired page
         else {
            curr -= steps;
            return history[curr];
        }
    }

  
    string forward(int steps) { // Time Complexity: O(1)
      // If (curr + steps) is greater than history size, That means that we will display the last page [index history.size() - 1]
        if (curr + steps >= history.size()) {
            curr = history.size() - 1;
            return history[curr]; }
      
      // Otherwise we will display the desired page
         else {
            curr += steps;
            return history[curr];
        }
    }
};
