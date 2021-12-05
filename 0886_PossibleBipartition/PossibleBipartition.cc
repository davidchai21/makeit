class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        for (vector<int>& d : dislikes) {
            graph[d[0]-1].push_back(d[1]-1);
            graph[d[1]-1].push_back(d[0]-1);
        }
        vector<int> color(N, 0);
        
        for (int i=0;i<N;++i) {
            if (graph[i].empty() || color[i]) continue;
            
            color[i] = 2;
            int c = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    int node = q.front();
                    q.pop();
                    for (int& k : graph[node]) {
                        if (!color[k]) {
                            color[k] = c;
                            q.push(k);
                        } else {
                            if (color[k] != c) return false;
                        }
                    }
                }
                c = 3-c;
            }
        }
        return true;
    }
};