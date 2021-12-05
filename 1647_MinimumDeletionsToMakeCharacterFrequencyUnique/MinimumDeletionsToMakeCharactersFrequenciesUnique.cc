class Solution {
public:
    int minDeletions(string s) {
        vector<int> record(26, 0);
        for (char& c : s) {
            ++record[c-'a'];
        }
        unordered_map<int, int> m;
        for (int k : record) {
            if (k) ++m[k];
        }
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            while (it->second > 1) {
                it->second -= 1;
                int count = 1;
                int f = it->first-1;
                while (f > 0 && m.find(f) != m.end()) {
                    --f;
                    ++count;
                }
                if (f > 0) m[f] = 1;
                res += count;
            }
        }
        return res;
    }
};