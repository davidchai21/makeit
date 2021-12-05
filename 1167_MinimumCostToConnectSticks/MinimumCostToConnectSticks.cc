class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if (sticks.size() == 1) return 0;
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int res = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            a += pq.top();
            pq.pop();
            res += a;
            pq.push(a);
        }
        return res;
    }
};