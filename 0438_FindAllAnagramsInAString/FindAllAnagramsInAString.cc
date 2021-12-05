class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (m > n) return {};
        vector<int> base(26, 0);
        int count = 0;
        for (char& c : p) {
            ++base[c-'a'];
            if (base[c-'a'] == 1) ++count;
        }
        vector<int> res;
        for (int i=0;i<n;++i) {
            int pos = s[i]-'a';
            --base[pos];
            if (base[pos] == 0) --count;
            else if (base[pos] == -1) ++count;
            if (i>=m-1) {
                if (!count) res.push_back(i-m+1);
                pos = s[i+1-m]-'a';
                ++base[pos];
                if (base[pos] == 0) --count;
                else if (base[pos] == 1) ++count;
            }
        }
        return res;
    }
};