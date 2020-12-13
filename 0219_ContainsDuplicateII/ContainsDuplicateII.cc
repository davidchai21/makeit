class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if (k<1) return false;
        unordered_set<int> s;
        for (int i=0;i<min(k,size);++i) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        for (int i=k;i<size;++i) {
            if (s.find(nums[i]) != s.end()) return true;
            s.erase(nums[i-k]);
            s.insert(nums[i]);
        }
        return false;
    }
};

// Shorter:

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k<1) return false;
        unordered_set<int> s;
        for (int i=0;i<nums.size();++i) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
            if (s.size()>k) s.erase(nums[i-k]);
        }
        return false;
    }
};