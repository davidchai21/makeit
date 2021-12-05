// Brute-force:

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int min_left = INT_MAX;
        for (int i=0;i<n-1;++i) {
            min_left = min(min_left, nums[i]);
            for (int j=i+1;j<n;++j) {
                if (min_left < nums[j] && nums[j] < nums[i]) return true;
            }
        }
        return false;
    }
};

// binary search:

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for (int i=n-1;i>1;--i) {
            ++m[nums[i]];
        }
        int min_num = nums.front();
        for (int i=1;i<n-1;++i) {
            auto k = m.upper_bound(min_num);
            if (k != m.end() && k->first < nums[i]) return true;
            --m[nums[i+1]];
            if (!m[nums[i+1]]) m.erase(nums[i+1]);
            min_num = min(min_num, nums[i]);
        }
        return false;
    }
};

