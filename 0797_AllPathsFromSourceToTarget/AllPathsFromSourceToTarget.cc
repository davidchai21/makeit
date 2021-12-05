class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        vector<bool> visited(n, false);
        visited.front() = true;
        vector<int> t;
        helper(res, graph, t, 0, visited);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<vector<int>>& graph, vector<int>& t, int node, vector<bool>& visited) {
        t.push_back(node);
        if (node == graph.size()-1) {
            res.push_back(t);
        } else {
            visited[node] = true;
            for (int& c : graph[node]) {
                helper(res, graph, t, c, visited);
            }
            visited[node] = false;
        }
        t.pop_back();
    }
};