class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        int n = words1.size();
        unordered_map<string, string> m;
        for (vector<string>& p : pairs) {
            if (m.find(p[0]) == m.end()) m[p[0]] = p[0];
            if (m.find(p[1]) == m.end()) m[p[1]] = p[1];
            string pa = _find(m, p[0]);
            string pb = _find(m, p[1]);
            if (pa == pb) continue;
            m[pa] = pb;
        }
        
        for (int i=0;i<n;++i) {
            if (words1[i] == words2[i] || _find(m, words1[i]) == _find(m, words2[i])) continue;
            return false;
        }
        return true;
    }
private:
    string _find(unordered_map<string, string>& m, string a) {
        while (m[a] != m[m[a]]) {
            m[a] = m[m[a]];
        }
        return m[a];
    }
};