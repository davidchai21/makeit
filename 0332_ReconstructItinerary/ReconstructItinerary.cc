class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        const string departure = "JFK";
        unordered_map<string, vector<pair<string, bool>>> m;
        for (vector<string>& i : tickets) {
            m[i[0]].push_back({i[1], false});
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end(), [](const pair<string, int>& lhs, const pair<string, int>& rhs){
                return lhs.first < rhs.first;
            });
        }
        vector<string> res;
        dfs(res, departure, tickets.size()+1, m);
        return res;
    }
private:
    bool dfs(vector<string>& res, const string city, int n, unordered_map<string, vector<pair<string, bool>>>& m) {
        res.push_back(city);
        if (res.size() == n) return true;
        
        for (pair<string, bool>& p : m[city]) {
            if (p.second) continue;
            p.second = true;
            if (dfs(res, p.first, n, m)) return true;
            p.second = false;
        }
        res.pop_back();
        return false;
    }
};