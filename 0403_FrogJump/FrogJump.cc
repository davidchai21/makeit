class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> m;
        for (int& s : stones) m[s];
        m[stones[0]].insert(0);
        for (int& stone : stones) {
            for (auto it = m[stone].begin(); it != m[stone].end(); ++it) {
                for (int k=*it-1; k<*it+2; ++k) {
                    if (k > 0 && m.find(k+stone) != m.end()) {
                        m[k+stone].insert(k);
                    }
                }
            }
        }
        return m[stones.back()].size();
    }
};