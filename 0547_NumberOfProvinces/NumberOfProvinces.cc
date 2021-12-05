class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n, -1);
        unordered_set<int> s;
        for (int i=0;i<n;++i) {
            if (parent[i] == -1) {
                parent[i] = i;
                dfs(parent, isConnected, i, n);
            }
            s.insert(parent[i]);
        }
        return s.size();
    }
private:
    typedef vector<vector<int>> vv;
    
    int _find(vector<int>& parent, int index) {
        while (parent[index] != parent[parent[index]]) {
            parent[index] = parent[parent[index]];
        }
        return parent[index];
    }
    
    void dfs(vector<int>& parent, vv& is, int from, const int& n) {
        for (int i=0;i<n;++i) {
            if (is[from][i] && i != from && parent[i]==-1) {
                parent[i] = _find(parent, from);
                dfs(parent, is, i, n);
            }
        }
    }
};

// DFS:

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        vector<bool> visited(isConnected.size(), false);
        for (int i=0;i<isConnected.size();++i) {
            if (!visited[i]) {
                ++res;
                dfs(isConnected, visited, i);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& con, vector<bool>& visited, int index) {
        visited[index] = true;
        
        for (int i=0;i<con.size();++i) {
            if (con[i][index] && !visited[i]) {
                dfs(con, visited, i);
            }
        }
    }
};

// BFS:

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> q;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i=0;i<n;++i) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                ++res;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    
                    for (int j=0;j<n;++j) {
                        if (isConnected[cur][j] && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return res;
    }
};