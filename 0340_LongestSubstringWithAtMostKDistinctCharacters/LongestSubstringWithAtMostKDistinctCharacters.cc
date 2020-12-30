class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (!k) return 0;
        int left = 0;
        int res = -1;
        int count = 0;
        unordered_map<char, int> m;
        for (int i=0;i<n;++i) {
            ++m[s[i]];
            if (m[s[i]] == 1) ++count;
            while (count > k) {
                --m[s[left]];
                if (m[s[left]] == 0) --count;
                ++left;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};