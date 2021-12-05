class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (q.empty() || q.back().first < timestamp) q.push_back(make_pair(timestamp, 1));
        else ++q.back().second;
        ++count;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && q.front().first+duration<=timestamp) {
            count -= q.front().second;
            q.pop_front();
        }
        return count;
    }
private:
    // time, count
    list<pair<int, int>> q;
    const int duration = 300;
    int count;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */