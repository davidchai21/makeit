class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, vector<string>> m;
        unordered_map<string, int> len;
        int max_len = 0;
        int res = 1;
        for (string & word : words) {
            m[word.size()].push_back(word);
            max_len = max(max_len, (int)word.size());
        }
        while (max_len) {
            if (m.find(max_len+1) == m.end()) {
                for (string& s : m[max_len]) {
                    len[s] = 1;
                }
            } else {
                for (string& s : m[max_len]) {
                    int ans = 0;
                    for (string& l : m[max_len+1]) {
                        if (check(s, l)) {
                            ans = max(ans, len[l]);
                        }
                    }
                    len[s] = ans+1;
                    res = max(res, len[s]);
                }
            }
            --max_len;
        }
        return res;
    }
private:
    bool check(string& s, string& l) {
        int m = s.size(), n = l.size();
        int i = 0, j = 0;
        bool flag = false;
        while (i < m && j<n) {
            if (s[i] != l[j]) {
                if (flag) return false;
                flag = true;
                ++j;
            } else {
                ++i, ++j;
            }
        }
        return true;
    }
};

// DP:

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m;
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        int res = 0;
        for (string & word : words) {
            for (int i=0;i<word.size();++i) {
                string t = word.substr(0, i) + word.substr(i+1);
                m[word] = max(m[word], (m.find(t) == m.end() ? 1 : 1+m[t]));
            }
            res = max(res, m[word]);
        }
        return res;
    }
};