class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> record(n);
        for (int i=0;i<n;++i) {
            record[i] = make_pair(efficiency[i], speed[i]);
        }
        sort(record.begin(), record.end(), greater<pair<int,int>>());
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;
        long res = 0L, sum = 0L;
        for (int i=0;i<n;++i) {
            pq.push(record[i]);
            sum += record[i].second;
            if (pq.size() > k) {
                sum -= pq.top().second;
                pq.pop();
            }
            res = max(record[i].first * sum, res);
        }
        return res%mod;
    }
private:
    const int mod = 1e9+7;
    
    struct Comp {
        bool operator() (pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        }
    };
};