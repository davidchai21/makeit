class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int maxCount = 0;
        int res = 0;
        for (int i=0;i<s.size();++i) {
            maxCount = max(maxCount, ++count[s[i]-'A']);
            if (i+1-maxCount-left > k) {
                --count[s[left]-'A'];
                ++left;
            }
            res = max(res, i+1-left);
        }
        return res;
    }
};