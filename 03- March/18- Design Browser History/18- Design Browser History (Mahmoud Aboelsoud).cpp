// Author: Mahmoud Aboelsoud

class BrowserHistory {
public:
    // vector to store the history
    vector<string> v;
    // index of the last visited page, and the current page
    int lst, cur;
    // constructor
    BrowserHistory(string homepage) {
        // push the homepage to the vector
        v.emplace_back(homepage);
        // set the last visited page to be the homepage and the current page to be the homepage
        lst = 0, cur = 0;
    }
    

    void visit(string url) {
        // if the current page is the last visited page, push the new url to the vector
        if(cur == v.size() - 1) v.emplace_back(url), cur++, lst++;
        // else, replace the next page with the new url and set the last visited page to be the current page (the new url)
        else v[++cur] = url, lst = cur;
    }
    
    string back(int steps) {
        // if the number of steps is greater than the current page, set the current page to be the homepage
        if(steps > cur) cur = 0;
        // else, subtract the number of steps from the current page
        else cur -= steps;

        // return the current page
        return v[cur];
    }
    
    string forward(int steps) {
        // if the number of steps is greater than the number of pages after the current page, set the current page to be the last visited page
        // else, add the number of steps to the current page
        cur = min(cur + steps, lst);

        // return the current page
        return v[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
