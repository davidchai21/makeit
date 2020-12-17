class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        int n = pid.size();
        for (int i=0;i<n;++i) {
            m[ppid[i]].push_back(pid[i]);
        }
        queue<int> q;
        q.push(kill);
        vector<int> res;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (int i=0;i<m[cur].size();++i) q.push(m[cur][i]);
        }
        return res;
    }
};