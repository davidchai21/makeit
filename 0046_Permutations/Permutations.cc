class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        vector<bool> visited(nums.size(), false);
        helper(nums, t, visited, res);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<int>& t, vector<bool>& visited, vector<vector<int>>& res) {
        if (t.size() == nums.size()) {
            res.push_back(t);
            return;
        }
        
        for (int i=0;i<nums.size();++i) {
            if (!visited[i]) {
                visited[i] = true;
                t.push_back(nums[i]);
                helper(nums, t, visited, res);
                t.pop_back();
                visited[i] = false;
            }
        }
    }
};

// Swap:

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, res, 0);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& res, int pos) {
        if (pos >= nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i=pos; i<nums.size(); ++i) {
            swap(nums[i], nums[pos]);
            helper(nums, res, pos+1);
            swap(nums[i], nums[pos]);
        }
    }
};