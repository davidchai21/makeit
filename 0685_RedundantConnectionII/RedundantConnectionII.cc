class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> parent(n+1);
        vector<bool> visited(n+1,false);
        int double_node = -1;
        vector<int> cycle;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            if (visited[u] && visited[v]) {
                cycle = edge;
            }
            visited[u] = true;
            visited[v] = true;
            
            parent[v].push_back(u);
            if (parent[v].size() > 1) {
                double_node = v;
            }
        }
        
        if (double_node == -1) {
            return cycle;
        }
        int p1 = parent[double_node][0];
        int p2 = parent[double_node][1];
        int cur = p1;
        while (!parent[cur].empty() && parent[cur][0] != double_node) {
            cur = parent[cur][0];
        }
        if (parent[cur].empty()) return {p2, double_node};
        return {p1, double_node};
    }
};