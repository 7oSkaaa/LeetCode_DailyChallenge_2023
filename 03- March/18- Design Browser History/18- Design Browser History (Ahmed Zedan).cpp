// author : Ahmed Zedan
class BrowserHistory {
public:
    /*
    *facebook
    *google
    *leetcode 
    */

    /*
    *youtube
    */
    stack<string>active,history ; 
    BrowserHistory(string homepage) {
        active.push(homepage) ; // push to active stack home page
    }
    
    void visit(string url) {
        history = stack<string>() ; //when visit new page clear all forward page 
        active.push(url) ; // push current url page 
    }
    
    string back(int steps) {
        //psuh all page before steps in history stack 
        while(steps--&&active.size()>1){
            string tmp = active.top() ; 
            history.push(tmp) ;
            active.pop() ;

        }
        return active.top() ; // return page after steps
    }
    
    string forward(int steps) {
        while(steps--&&!history.empty()){
            string tmp = history.top() ; 
            active.push(tmp) ; 
            history.pop() ; 
        }
        return active.top() ; 
    }
};