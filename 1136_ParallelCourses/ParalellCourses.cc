class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> degree(n, 0);
        vector<vector<int>> course(n, vector<int>());
        for (vector<int>& relation : relations) {
            ++degree[relation.back()-1];
            course[relation[0]-1].push_back(relation[1]-1);
        }
        queue<int> q;
        int count = 0;
        for (int i=0;i<n;++i) {
            if (!degree[i]) {
                q.push(i);
                ++count;
            }
        }
        
        int res = 0;
        while (!q.empty()) {
            ++res;
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                for (int& i : course[cur]) {
                    if (--degree[i] == 0) {
                        q.push(i);
                        ++count;
                    }
                }
            }
        }
        return count == n ? res : -1;
    }
};

// DFS:

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> degree(n, 0);
        vector<vector<int>> course(n, vector<int>());
        for (vector<int>& relation : relations) {
            ++degree[relation.back()-1];
            course[relation[0]-1].push_back(relation[1]-1);
        }
        vector<int> result(n, -1);
        vector<bool> visited(n, false);
        int res = -1;
        for (int i=0;i<n;++i) {
            int cur = dfs(result, i, course, visited);
            if (cur == -1) return -1;
            res = max(res, cur);
        }
        return res;
    }
private:
    int dfs(vector<int>& result, int index, vector<vector<int>>& course, vector<bool>& visited) {
        if (visited[index]) return -1;
        if (result[index] != -1) return result[index];
        
        visited[index] = true;
        int depth = 1;
        for (int& c : course[index]) {
            int cur = dfs(result, c, course, visited);
            if (cur == -1) {
                depth = -1;
                break;
            }
            depth = max(depth, 1+cur);
        }
        visited[index] = false;
        result[index] = depth;
        return depth;
    }
};