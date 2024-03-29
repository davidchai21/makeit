class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 0);
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        helper(res, 0, -1, graph, labels);
        return res;
    }
private:
    array<int, 26> helper(vector<int>& res, int index, int parent, vector<vector<int>>& graph, const string& labels) {
        array<int, 26> count{};
        for (int& c : graph[index]) {
            if (c != parent) {
                array<int, 26> cur = helper(res, c, index, graph, labels);
                for (int i=0;i<26;++i) {
                    count[i] += cur[i];
                }
            }
        }
        
        res[index] = ++count[labels[index]-'a'];
        return count;
    }
};