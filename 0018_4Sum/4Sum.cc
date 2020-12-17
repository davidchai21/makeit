class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        unordered_set<string> s;
        for (int i=0;i<n-3;++i) {
            for (int j=i+1;j<n-2;++j) {
                helper(res, nums, nums[i], nums[j], j+1, s, target-nums[i]-nums[j]);
            }
        }
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& nums, int pre0, int pre1, int index, unordered_set<string>& s, int target) {
        int left = index, right = nums.size()-1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                string str = getKey(pre0, pre1, nums[left], nums[right]);
                if (s.find(str) == s.end()) {
                    s.insert(str);
                    res.push_back({pre0, pre1, nums[left], nums[right]});
                }
                ++left;
                --right;
            } else if (nums[left] + nums[right] < target) ++left;
            else --right;
        }
    }
    
    string getKey(int pre0, int pre1, int cur0, int cur1) {
        return to_string(pre0) + "#" + to_string(pre1) + "#" + to_string(cur0) + "#" + to_string(cur1);
    }
};