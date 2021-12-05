class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> m;
        for (const string& str : strs) {
            ++m[str];
        }
        vector<string> s(m.size());
        int index = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            s[index++] = it->first;
        }
        sort(s.begin(), s.end(), [](const string& a, const string& b){
            return a.size() > b.size();
        });
        
        for (int i=0;i<s.size();++i) {
            if (m[s[i]] == 1) {
                int j = 0;
                for (;j<i;++j) {
                    if (isSubseq(s[i], s[j])) break;
                }
                if (j == i) return s[i].size();
            }
        }
        return -1;
    }
private:
    bool isSubseq(const string& a, const string& b) {
        size_t i=0;
        for (size_t j=0;j<b.size() && i<a.size();++j) {
            if (a[i] == b[j]) ++i;
        }
        return i == a.size();
    }
};

// Another:

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        size_t n = strs.size();
        for (size_t i=0;i<n;++i) {
            size_t j=0;
            for (;j<n;++j) {
                if (i==j) continue;
                if (match(strs[i], strs[j])) break;
            }
            if (j==n) res = max(res, static_cast<int>(strs[i].size()));
        }
        return res;
    }
private:
    bool match(string& a, string& b) {
        if (b.size() < a.size()) return false;
        size_t i=0;
        for (char& c : b) {
            if (i<a.size() && c==a[i]) ++i;
        }
        return i == a.size();
    }
};