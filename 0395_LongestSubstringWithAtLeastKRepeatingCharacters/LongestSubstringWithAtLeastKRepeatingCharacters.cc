class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> record(26, 0);
        for (const char& c : s) ++record[c-'a'];
        unordered_set<char> st;
        for (int i=0;i<26;++i) {
            if (record[i] && record[i] < k) st.insert('a'+i);
        }
        if (st.empty()) {
            return s.size();
        }
        
        int res = 0;
        int left = -1;
        for (int i=0;i<s.size();++i) {
            if (st.find(s[i]) != st.end()) {
                res = max(res, longestSubstring(s.substr(left+1, i-left-1), k));
                left = i;
            }
        }
        res = max(res, longestSubstring(s.substr(left+1), k));
        return res;
    }
};