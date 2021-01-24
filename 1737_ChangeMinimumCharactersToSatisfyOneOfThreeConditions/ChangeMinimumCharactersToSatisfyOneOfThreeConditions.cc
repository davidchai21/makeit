class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> c1(26, 0), c2(26, 0);
        for (char& c : a) ++c1[c-'a'];
        for (char& c : b) ++c2[c-'a'];
        
        int res = m+n;
        for (int i=0;i<26;++i) {
            res = min(res, m+n-c1[i]-c2[i]);
            if (i) {
                c1[i] += c1[i-1];
                c2[i] += c2[i-1];
            }
            if (i<25) {
                res = min(res, m-c1[i]+c2[i]);
                res = min(res, n-c2[i]+c1[i]);
            }
        }
        return res;
    }
};