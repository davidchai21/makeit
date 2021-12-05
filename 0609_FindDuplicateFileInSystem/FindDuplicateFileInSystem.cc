class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (string& path : paths) {
            stringstream ss(path);
            string prefix, file;
            ss >> prefix;
            prefix.push_back('/');
            while (ss >> file) {
                size_t pos = file.find('(');
                m[file.substr(pos+1, file.size()-pos-2)].push_back(prefix + file.substr(0, pos));
            }
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second.size() > 1) {
                res.push_back(it->second);
            }
        }
        return res;
    }
};