class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> record;
        for (int i=0;i<equations.size(); ++i) {
            record[equations[i][0]][equations[i][1]] = values[i];
            record[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        
        int n = queries.size();
        vector<double> res(n, -1);
        for (int i=0;i<n;++i) {
            if (record.find(queries[i].front()) == record.end() || record.find(queries[i].back()) == record.end()) continue;
            if (queries[i].front() == queries[i].back()) {
                res[i] = 1.0;
            } else {
                unordered_set<string> visited;
                double val = 1.0;
                if (dfs(record, queries[i].front(), queries[i].back(), val, visited)) res[i] = val;
            }
        }
        return res;
    }
private:
    bool dfs(unordered_map<string, unordered_map<string, double>>& record, string d, string t, double& res, unordered_set<string>& visited) {
        if (d == t) return true;
        if (visited.find(d) != visited.end()) return false;
        visited.insert(d);
        
        for (auto it = record[d].begin(); it != record[d].end(); ++it) {
            res *= it->second;
            if (dfs(record, it->first, t, res, visited)) {
                return true;
            }
            res /= it->second;
        }
        visited.erase(d);
        return false;
    }
};