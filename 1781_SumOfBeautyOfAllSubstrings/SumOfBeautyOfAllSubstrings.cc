class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for (int i=0;i<n;++i) {
            vector<int> count(26, 0);
            int big = INT_MIN;
            int small = INT_MAX;
            for (int j=i;j<n;++j) {
                int pos = s[j] - 'a';
                ++count[pos];
                big = max(big, count[pos]);
                small = count[pos];
                for (int& c : count) {
                    if (c) small = min(small, c);
                }
                res += big - small;
            }
        }
        return res;
    }
};