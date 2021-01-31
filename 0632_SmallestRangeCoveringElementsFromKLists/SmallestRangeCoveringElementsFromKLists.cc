class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        if (n==1) return {nums[0][0], nums[0][0]};
        
        vector<int> res;
        auto Comp = [&](pair<int,int>& a, pair<int,int>& b) {
            return nums[a.first][a.second] > nums[b.first][b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(Comp)> pq(Comp);
        int maxNum = INT_MIN;
        for (int i=0; i<n; ++i) {
            pq.push(make_pair(i, 0));
            maxNum = max(maxNum, nums[i][0]);
        }
        res = {nums[pq.top().first][pq.top().second], maxNum};
        
        bool isEnd = false;
        while (!isEnd) {
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            if (maxNum - nums[x][y] < res[1]-res[0]) {
                res[0] = nums[x][y];
                res[1] = maxNum;
            }
            if (y == nums[x].size()-1) {
                isEnd = true;
            } else {
                maxNum = max(maxNum, nums[x][y+1]);
                pq.push(make_pair(x, y+1));
            }
        }
        return res;
    }
};