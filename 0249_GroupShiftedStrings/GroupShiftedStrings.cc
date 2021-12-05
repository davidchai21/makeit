class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (string& s : strings) {
            m[hash(s)].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
private:
    string hash(string& s) {
        string res = "";
        char& c = s.front();
        for (char& x : s) {
            res += to_string((x-c+26)%26)+",";
        }
        return res;
    }
};