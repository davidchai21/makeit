class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for (int i=0;i<nums.size();++i) {
            if (s.size()>k) s.erase(nums[i-k-1]);
            auto it = s.lower_bound((long)nums[i]-t);
            if (it!=s.end() && *it-nums[i]<=t) return true;
            s.insert(nums[i]);
        }
        return false;
    } 
};

// Bucket 

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (!k) return false;
        unordered_map<int,long> m;
        for (int i=0;i<nums.size();++i) {
            if (m.size() > k) m.erase(nums[i-k-1]/((long)t+1));
            int key = nums[i]/((long)t+1);
            if (nums[i]<0) --key;
            if (m.find(key) != m.end()) return true;
            if (m.find(key-1) != m.end() && m[key-1]+t>=nums[i]) return true;
            if (m.find(key+1) != m.end() && m[key+1]-t<=nums[i]) return true;
            m[key] = nums[i];
        }
        return false;
    }
};