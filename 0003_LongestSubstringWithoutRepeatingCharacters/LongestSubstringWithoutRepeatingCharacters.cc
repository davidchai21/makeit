class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int res = 0;
        int pre = 0;
        for (int i=0;i<s.size();++i) {
            if (m.find(s[i]) != m.end()) {
                pre = max(pre, m[s[i]] + 1);
            }
            m[s[i]] = i;
            res = max(res, i-pre+1);
        }
        return res;
    }
};