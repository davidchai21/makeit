class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size()+1;
        unordered_map<int, vector<int>> m;
        for (vector<int>& p : adjacentPairs) {
            m[p[0]].push_back(p[1]);
            m[p[1]].push_back(p[0]);
        }
        int start = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second.size() == 1) {
                start = it->first;
                break;
            }
        }

        vector<int> res(n);
        int index = 0;
        while (index < n) {
            res[index++] = start;
            if (m[start].size() == 1) start = m[start].back();
            else {
                start = m[start][0] == res[index-2] ? m[start][1] : m[start][0];
            }
        }
        return res;
    }
};