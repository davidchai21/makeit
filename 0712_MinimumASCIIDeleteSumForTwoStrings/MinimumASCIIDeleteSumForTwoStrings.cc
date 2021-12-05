class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> res(n+1, 0), t(n+1);
        for (int i=1;i<=n;++i) res[i] = res[i-1]+s2[i-1];
        int sum = 0;
        for (int i=1;i<=m;++i) {
            sum += s1[i-1];
            t[0] = sum;
            for (int j=1;j<=n;++j) {
                if (s1[i-1] == s2[j-1]) t[j] = res[j-1];
                else t[j] = min(t[j-1]+s2[j-1], res[j]+s1[i-1]);
            }
            res.swap(t);
        }
        return res.back();
    }
};