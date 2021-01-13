class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        if (edges.size() < 2) return edges.size();
        unordered_map<int, vector<int>> m;
        for (vector<int>& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        int farNode = -1;
        helper(0, farNode, m);
        return helper(farNode, farNode, m);
    }
private:
    int helper(int start, int& res, unordered_map<int, vector<int>>& m) {
        int len = -1;
        queue<int> q({start});
        vector<bool> visited(m.size(), false);
        while (!q.empty()) {
            int size = q.size();
            res = -1;
            while (size--) {
                int cur = q.front();
                q.pop();
                if (res < 0) res = cur;
                visited[cur] = true;
                for (int k : m[cur]) {
                    if (!visited[k]) q.push(k);
                }
            }
            ++len;
        }
        return len;
    }
};