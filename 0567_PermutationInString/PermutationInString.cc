class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) return false;
        
        vector<int> dic(26, 0);
        for (int i=0;i<m;++i) {
            ++dic[s2[i]-'a'];
            --dic[s1[i]-'a'];
        }
        int diff = 0;
        for (int& k : dic) {
            if (k != 0) ++diff;
        }
        if (!diff) return true;
        
        for (int i=m;i<n;++i) {
            if (s2[i] == s2[i-m]) continue;
            int pos = s2[i-m]-'a';
            if (dic[pos] == 0) ++diff;
            if (--dic[pos] == 0) --diff;
            pos = s2[i]-'a';
            if (dic[pos] == 0) ++diff;
            if (++dic[pos] == 0) --diff;
            if (!diff) return true;
        }
        return false;
    }
};