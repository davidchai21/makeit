class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front()+diff<t) q.pop();
        return q.size();
    }
private:
    queue<int> q;
    const int diff = 3000;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */