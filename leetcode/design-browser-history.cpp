// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
public:

    BrowserHistory(string homepage) {
        while (v.size() > 0) {
            v.pop_back();
        }
        v.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        while (cur < v.size()-1) {
            v.pop_back();
        }
        v.push_back(url);
        cur = v.size()-1;
    }
    
    string back(int steps) {
        cur = max(cur - steps, 0);
        return v[cur];
    }
    
    string forward(int steps) {
        int sz = v.size();
        cur = min(cur + steps, sz - 1);
        return v[cur];
    }

    private:
        vector<string> v;
        int cur;

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */