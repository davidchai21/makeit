class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string& str : strs) {
            m[getKey(str)].push_back(str);
        }
        vector<vector<string>> res(m.size());
        int index = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res[index++] = it->second;
        }
        return res;
    }
private:
    inline string getKey(string& str) {
        vector<int> dic(26, 0);
        for (const char& c : str) {
            ++dic[c-'a'];
        }
        string res = "";
        for (int i=0;i<26;++i) {
            if (dic[i]) {
                res.push_back('a'+i);
                res+=to_string(dic[i]);
            }
        }
        return res;
    }
};