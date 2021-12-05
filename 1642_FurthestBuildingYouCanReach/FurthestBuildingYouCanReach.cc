class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 1;
        int n = heights.size();
        for (;res < n;++res) {
            if (heights[res] > heights[res-1]) {
                pq.push(heights[res]-heights[res-1]);
                if (pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();
                }
                if (bricks < 0) break;
            }
        }
        return res-1;
    }
};