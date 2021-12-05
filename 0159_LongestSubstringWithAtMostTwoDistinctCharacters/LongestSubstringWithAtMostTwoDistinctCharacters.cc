class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<int, int> m;
        int res = 0;
        int len = 0;
        int left = 0;
        for (char& c : s) {
            ++m[c];
            ++len;
            while (m.size() > 2) {
                --m[s[left]];
                --len;
                if (!m[s[left]]) {
                    m.erase(s[left]);
                }
                ++left;
            }
            res = max(res, len);
        }
        return res;
    }
};