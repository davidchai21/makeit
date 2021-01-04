class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        unordered_set<string> dir;
        unordered_map<int, vector<int>> m;
        unordered_set<int> seen;
        for (vector<int>& con : connections) {
            dir.insert(form(con[0], con[1]));
            m[con[1]].push_back(con[0]);
            m[con[0]].push_back(con[1]);
        }
        
        queue<int> q({0});
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            seen.insert(cur);
            for (int& city : m[cur]) {
                if (seen.find(city) == seen.end()) {
                    q.push(city);
                    if (dir.find(form(city, cur)) == dir.end()) ++res;
                }
            }
        }
        return res;
    }
private:
    string form(int& start, int& end) {
        return to_string(start) + "-" + to_string(end);
    }
};