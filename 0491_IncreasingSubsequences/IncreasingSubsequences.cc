class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        for (int i=0;i<nums.size();++i) {
            vector<int> t = {nums[i]};
            dfs(s, t, nums, i+1);
        }
        return vector<vector<int>>(s.begin(), s.end());
    }
private:
    void dfs(set<vector<int>>& s, vector<int>& t, vector<int>& nums, int index) {
        if (index == nums.size()) return;
        if (nums[index] < t.back()) dfs(s, t, nums, index+1);
        else {
            t.push_back(nums[index]);
            s.insert(t);
            dfs(s, t, nums, index+1);
            t.pop_back();
            dfs(s, t, nums, index+1);
        }
    }
};

// Better:

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        dfs(nums, 0, res, t);
        return res;
    }
private:
    void dfs(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& t) {
        if (t.size() > 1) {
            res.push_back(t);
        }
        
        unordered_set<int> s;
        for (int i=index;i<nums.size();++i) {
            if ((t.empty() || t.back() <= nums[i]) && s.find(nums[i]) == s.end()) {
                t.push_back(nums[i]);
                s.insert(nums[i]);
                dfs(nums, i+1, res, t);
                t.pop_back();
            }
        }
    }
};