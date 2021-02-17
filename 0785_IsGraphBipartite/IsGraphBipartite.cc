class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        
        for (int i=0;i<n;++i) {
            if (!color[i]) {
                color[i] = 1;
                q.push(i);
                while (!q.empty()) {
                    int size = q.size();
                    while (size--) {
                        int index = q.front();
                        q.pop();
                        
                        for (int& k : graph[index]) {
                            if (!color[k]) {
                                color[k] = -color[index];
                                q.push(k);
                            } else if (color[k] == color[index]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};