class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res(n-k+1);
        for (int i=0;i<n;++i) {
            if (!dq.empty() && dq.back() == i-k) dq.pop_back();
            while (!dq.empty() && nums[dq.front()] < nums[i]) dq.pop_front();
            dq.push_front(i);
            if (i+1>=k) res[i+1-k] = nums[dq.back()];
        }
        return res;
    }
};