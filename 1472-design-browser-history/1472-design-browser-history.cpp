class BrowserHistory {
public:
    vector<string> history;
    int pos;
    BrowserHistory(string homepage) {
        pos = 0;
        history.push_back(homepage);
    }
    
    void visit(string url) {
        pos++;
        history.resize(pos);
        history.push_back(url);
    }
    
    string back(int steps) {
        pos = max(0,pos-steps);
        return history[pos];
    }
    
    string forward(int steps) {
        pos = min((int)history.size()-1,pos+steps);
        return history[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */