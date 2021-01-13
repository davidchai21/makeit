class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int res = 0;
        unordered_map<int, vector<int>> m;
        for (vector<int>& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        helper(m, hasApple, 0, -1, res);
        return res;
    }
private:
    bool helper(unordered_map<int, vector<int>>& m, vector<bool>& has, int root, int parent, int& res) {
        bool flag = false;
        for (int& k : m[root]) {
            if (k != parent) {
                bool cur = helper(m, has, k, root, res);
                if (cur) res += 2;
                flag |= cur;
            }
        }
        return flag || has[root];
    }
};