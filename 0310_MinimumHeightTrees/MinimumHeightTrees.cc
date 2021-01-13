class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> m;
        for (vector<int>& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        
        queue<int> q;
        vector<int> res;
        for (int i=0;i<n;++i) {
            if (degree[i] == 1) q.push(i);
        }
        while (!q.empty()) {
            res.clear();
            int size = q.size();
            for (int i=0;i<size;++i) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for (int e : m[cur]) {
                    if (--degree[e] == 1) q.push(e);
                }
            }
        }
        return res;
    }
};