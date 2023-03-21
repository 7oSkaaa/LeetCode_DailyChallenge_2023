// Author: Ahmed Hossam

class BrowserHistory {
public:
    
    // to store the size and current index of the tab
    int sz, currIdx;

    // to store the urls 
    vector < string > history;

    // constructor to initialize the vector with homepage
    BrowserHistory(string& homepage) {
        history.push_back(homepage);
        sz = 1, currIdx = 0;
    }

    void visit(const string& url) {
        // If the user has gone back in history and is now adding a new URL, 
        // the forward history from the current position should be removed.
        if(currIdx + 1 < history.size())
            history[++currIdx] = url, sz = currIdx + 1;
        else 
            history.push_back(url), sz++, currIdx++;
    }
    
    // This function moves the user back in the history by the specified number of steps.
    // If the user has reached the beginning of the history, it returns the first URL in the history.
    string back(int steps) {
        currIdx = max(currIdx - steps, 0);
        return history[currIdx];
    }
    
    // This function moves the user forward in the history by the specified number of steps.
    // If the user has reached the end of the history, it returns the last URL in the history.
    string forward(int steps) {
        currIdx = min(currIdx + steps, sz - 1);
        return history[currIdx];
    }
};
