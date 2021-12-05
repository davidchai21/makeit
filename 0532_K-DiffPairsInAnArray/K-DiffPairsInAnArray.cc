class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> m;
        for (int & num : nums) ++m[num];
        int res = 0;
        
        if (!k) {
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (it->second > 1) ++res;
            }
            return res;
        }
        
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (m.find(it->first + k) != m.end()) ++res;
        }
        return res;
    }
};

// O(n):

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return n-1;
        
        unordered_map<int, int> m;
        for (int & num : nums) ++m[num];
        
        int res = 0;
        if (!k) {
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (it->second > 1) ++res;
            }
        } else {
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (m.find(it->first + k) != m.end()) ++res;
            }
        }
        return res;
    }
};