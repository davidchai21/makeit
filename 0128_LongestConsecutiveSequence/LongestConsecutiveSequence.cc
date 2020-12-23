class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n:nums) s.insert(n);
        int res = 0;
        while (!s.empty()) {
            int left = *s.begin();
            s.erase(*s.begin());
            int right = left;
            bool f = true;
            while (f) {
                f = false;
                if (s.find(left-1) != s.end()) {
                    s.erase(left-1);
                    --left;
                    f = true;
                }
                if (s.find(right+1) != s.end()) {
                    s.erase(right+1);
                    ++right;
                    f = true;
                }
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};