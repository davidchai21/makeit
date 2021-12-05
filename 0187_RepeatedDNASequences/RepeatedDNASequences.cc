class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 11) return res;
        
        unordered_map<string, int> m;
        string t = s.substr(0, 10);
        ++m[t];
        for (int i=10;i<s.size();++i) {
            t = t.substr(1)+s[i];
            ++m[t];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > 1) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};