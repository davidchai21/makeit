class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> record(target+1, 0);
        record[0] = 1;
        for (int i=1;i<=target;++i) {
            for (int &num : nums) {
                if (i < num) continue;
                record[i] += record[i-num];
            }
        }
        return record.back();
    }
};

// Top-down:

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> record(target+1, -1);
        record[0] = 1;
        return dfs(nums, record, target);
    }
private:
    int dfs(vector<int>& nums, vector<int>& record, int target) {
        if (record[target] != -1) return record[target];
        
        int res = 0;
        for (int& num : nums) {
            if (target >= num) res += dfs(nums, record, target-num);
        }
        return record[target] = res;
    }
};