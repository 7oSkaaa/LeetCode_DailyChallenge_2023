// Author: Mina Magdy

class BrowserHistory {
public:
    vector<string> vec;
    int i, sz;
    BrowserHistory(string homepage) {
        // push homepage url in our vector history
        vec.push_back(homepage);
        // i denotes the current url index
        i = 0;
        // sz denotes the size of the history
        sz = 1;
    }
    
    void visit(string url) {
        // if i indecates to last url push the new visited url to the vector and increment both i and sz
        if (int(vec.size()) == i + 1) {
            vec.push_back(url);
            i++;
            sz++;
        }
        else { // this means that i have go back and visited a page this will destroy all forward urls by assigning sz to i + 1
            vec[++i] = url;
            sz = i + 1;
        }
    }
    
    string back(int steps) {
        i = max(0, i - steps);
        return vec[i];
    }
    
    string forward(int steps) {
        i = min(sz - 1, i + steps);
        return vec[i];
    }
};
