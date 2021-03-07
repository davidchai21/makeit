// Without Sorting

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_set<int> s;
        unordered_map<int, int> seen;
        for (int i=0;i<nums.size();++i) {
            if (s.insert(nums[i]).second) {
                for (int j=i+1;j<nums.size();++j) {
                    int rest = -nums[i]-nums[j];
                    auto it = seen.find(rest);
                    if (it != seen.end() && it->second == i) {
                        vector<int> triplet = {nums[i], nums[j], rest};
                        sort(triplet.begin(), triplet.end());
                        res.insert(triplet);
                    }
                    seen[nums[j]] = i;
                }
            }
        }
        vector<vector<int>> ans(begin(res), end(res));
        return ans;
    }
};

// Sorting:

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        
        sort(nums.begin(), nums.end());
        for (int i=0;i<n-2;) {
            int left = i+1, right = n-1;
            while (left < right) {
                if (nums[left] + nums[right] == -nums[i]) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left+1] == nums[left]) ++left;
                    while (left < right && nums[right-1] == nums[right]) --right;
                    ++left;
                    --right;
                }
                else if (nums[left] + nums[right] < -nums[i]) ++left;
                else --right;
            }
            while (i<n-2 && nums[i+1] == nums[i]) ++i;
            ++i;
        }
        return res;
    }
};