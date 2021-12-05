class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        int res = 0;
        for (int& ans : answers) ++m[ans];
        for (auto it = m.begin(); it != m.end(); ++it) {
            int k = it->second/(it->first+1);
            res += k*(it->first+1);
            if (it->second%(it->first+1)) res += it->first+1;
        }
        return res;
    }
};