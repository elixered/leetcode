class BrowserHistory {
public:
    stack<string> before,after;
    BrowserHistory(string homepage) {
        before.push(homepage);
    }
    
    void visit(string url) {
        stack<string> temp;
        after = temp;
        before.push(url);
    }
    
    string back(int x) {
        while(before.size()>1 && x>0)
        {
            x--;
            after.push(before.top());
            before.pop();
        }
        return before.top();
    }
    
    string forward(int x) {
        while(after.size()>0 && x>0)
        {
            x--;
            before.push(after.top());
            after.pop();
        }
        return before.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */