class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<string> name(n);
        vector<int> parent(n);
        for (int i=1;i<n;++i) parent[i] = i;
        unordered_map<string, int> m;
        for (int i=0;i<n;++i) {
            name[i] = accounts[i].front();
            for (int j=1;j<accounts[i].size();++j) {
                if (m.find(accounts[i][j]) == m.end()) {
                    m[accounts[i][j]] = i;
                } else {
                    _union(m[accounts[i][j]], i, parent);
                }
            }
        }
        unordered_map<int, vector<string>> record;
        for (auto it = m.begin(); it != m.end(); ++it) {
            int p = _find(it->second, parent);
            if (record[p].empty()) {
                record[p].push_back(name[p]);
            }
            record[p].push_back(it->first);
        }
        vector<vector<string>> res;
        for (auto it = record.begin(); it != record.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
        }
        return res;
    }
private:
    int _find(int cur, vector<int>& parent) {
        while (parent[cur] != parent[parent[cur]]) {
            parent[cur] = parent[parent[cur]];
        }
        return parent[cur];
    }
    
    bool _union(int a, int b, vector<int>& parent) {
        int pa = _find(a, parent);
        int pb = _find(b, parent);
        if (pa == pb) return false;
        parent[pa] = pb;
        return true;
    }
};