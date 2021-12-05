class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dic(26, -1);
        int n = s.size();
        for (int i=0;i<n;++i) {
            int pos = s[i]-'a';
            if (dic[pos] == -1) dic[pos] = i;
            else if (dic[pos] >= 0) dic[pos] = -2;
        }
        
        int res = n;
        for (int& d : dic) {
            if (d >= 0) res = min(d, res);
        }
        return res == n ? -1 : res;
    }
};