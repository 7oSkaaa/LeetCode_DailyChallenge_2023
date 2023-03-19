//Author: Sara Hamza

/*Approach
solved the problem using a vector that represents our history and keep tacking of the index of the current page in this history as well.
*/

class BrowserHistory {
public:
    /* history : the history of our browser
       currPageIdx : index of the current page in this history
    */
    vector<string> history;
    int currPageIdx;

    BrowserHistory(string homepage) {
        // initializing the history with this home page :
        history.push_back(homepage);
        currPageIdx = 0;
    }

    void visit(string url) {
        // delete all of the forward pages
        history.resize(currPageIdx + 1);
        // put this url in the history
        history.push_back(url);
        // keep the currPageIdx referring to this url
        ++currPageIdx;
    }

    string back(int steps) {
        /* check if steps > backward history pages :
            go to the first page in the backward history
           otherwise :
            decrement the currPageIdx by the number of steps to go to the target page
        */
        currPageIdx = (currPageIdx < steps ? 0 : currPageIdx - steps);
        return history[currPageIdx];
    }

    string forward(int steps) {
        // the same idea of back function
        /* check if the currPagesIdx + steps needed is greater than our history's size :
            go to the last page in our history
           otherwise :
            decrement by the needed steps
        */
        int sz = history.size();
        currPageIdx = (steps + currPageIdx >= sz ? sz - 1 : currPageIdx + steps);
        return history[currPageIdx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
