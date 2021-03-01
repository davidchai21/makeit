class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        curSite = homepage;
    }
    
    void visit(string url) {
        f = stack<string>();
        b.push(curSite);
        curSite = url;
    }
    
    string back(int steps) {
        while (steps-- && !b.empty()) {
            f.push(curSite);
            curSite = b.top();
            b.pop();
        }
        return curSite;
    }
    
    string forward(int steps) {
        while (steps-- && !f.empty()) {
            b.push(curSite);
            curSite = f.top();
            f.pop();
        }
        return curSite;
    }
private:
    stack<string> b, f;
    string curSite;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// Using vector:

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        index = 0;
        history.push_back(homepage);
    }
    
    void visit(string url) {
        history.resize(++index);
        history.push_back(url);
    }
    
    string back(int steps) {
        while (index && steps--) {
            --index;
        }
        return history[index];
    }
    
    string forward(int steps) {
        while (index < history.size()-1 && steps--) {
            ++index;
        }
        return history[index];
    }
private:
    vector<string> history;
    int index;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// Using List:

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        history.erase(++it, history.end());
        it = history.insert(history.end(), url);
    }
    
    string back(int steps) {
        while (steps-- && it != history.begin()) --it;
        return *it;
    }
    
    string forward(int steps) {
        while (steps-- && it != history.end()) ++it;
        if (it == history.end()) --it;
        return *it;
    }
private:
    list<string> history;
    list<string>::iterator it;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */