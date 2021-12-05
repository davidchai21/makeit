class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int size = pow(2, n);
        vector<vector<int>> res(size);
        for (int num = 0;num<size;++num) {
            vector<int> t;
            for (int j=0;j<n;++j) {
                if (num & (1<<j)) t.push_back(nums[j]);
            }
            res[num] = t;
        }
        return res;
    }
};

// Backtracking:

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        helper(nums, 0, t, res);
        return res;
    }
private:
    void helper(vector<int>& nums, int index, vector<int>& t, vector<vector<int>>& res) {
        if (nums.size() == index) {
            res.push_back(t);
            return;
        }
        
        helper(nums, index+1, t, res);
        t.push_back(nums[index]);
        helper(nums, index+1, t, res);
        t.pop_back();
    }
};

// Append:

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        res.push_back({nums.front()});
        int n = 2;
        for (int i=1;i<nums.size();++i) {
            for (int j=0;j<n;++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
            n <<= 1;
        }
        return res;
    }
};