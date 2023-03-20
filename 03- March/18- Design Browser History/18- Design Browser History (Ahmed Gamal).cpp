// Author: Ahmed Gamal

// for this problem we just need to implement what is mentioned in the problem statement and try to make these operations efficient
// the operations are visit, back and forward
// the visit operation is easy to implement, we just need to add the url to the history and update the current index
// but before we add the url to the history we need to remove all the urls after the current index
// and if we use vector, we don't need to actually remove the urls, we can just resize the vector to the current index + 1 and add the new url
// the back operation is easy to implement, we just need to decrease the current index by the number of steps and return the url at the current index
// but we need to make sure that the current index is not less than 0
// the forward operation is easy to implement, we just need to increase the current index by the number of steps and return the url at the current index
// but we need to make sure that the current index is not greater than the size of the history - 1

class BrowserHistory {
    vector<string> history;
    int idx;
public:
    BrowserHistory(string homepage) {
        history = {homepage};
        idx = 0;
    }
    
    void visit(string url) {
        history.resize(idx + 1);
        history.emplace_back(url);
        idx++;
    }
    
    string back(int steps) {
        idx = max(idx - steps, 0);
        return history[idx];
    }
    
    string forward(int steps) {
        idx = min(idx + steps, (int)history.size() - 1);
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */