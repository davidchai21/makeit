class Solution {
public:
    int maxScore(vector<int>& nums) {
        unordered_map<int, int> m;
        return helper(0, nums, m, 1);
    }
private:
    int helper(int mask, vector<int>& nums, unordered_map<int, int>& m, int base) {
        if (base*2 > nums.size()) return 0;
        if (m.find(mask) != m.end()) return m[mask];
        
        int res = 0;
        for (int i=0;i<nums.size();++i) {
            if ((mask & (1<<i)) != 0) continue;
            for (int j=i+1;j<nums.size();++j) {
                if ((mask & (1<<j)) != 0) continue;
                res = max(res, base*gcd(nums[i], nums[j]) + helper(mask | (1<<i) | (1<<j), nums, m, base+1));
            }
        }
        
        return m[mask] = res;
    }
};

// Another:

class Solution {
public:
    int maxScore(vector<int>& nums) {
        unordered_map<int, int> m;
        return helper((1<<nums.size())-1, nums, m, nums.size()/2);
    }
private:
    int helper(int mask, vector<int>& nums, unordered_map<int, int>& m, int base) {
        if (base <= 0) return 0;
        if (m.find(mask) != m.end()) return m[mask];
        vector<int> bit;
        for (int i=0;i<nums.size();++i) {
            if ((1<<i) & mask) bit.push_back(i);
        }
        
        int res = 0;
        for (int i=0;i<bit.size();++i) {
            for (int j=i+1;j<bit.size();++j) {
                int new_mask = mask & ~(1<<bit[i]) & ~(1<<bit[j]);
                res = max(res, base*gcd(nums[bit[i]], nums[bit[j]])+helper(new_mask, nums, m, base-1));
            }
        }
        
        return m[mask] = res;
    }
};