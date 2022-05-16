class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string code = "";
        for (string& word : words) {
            string t = hash(word);
            if (res.empty() || code != t) {
                res.push_back(word);
            }
            t.swap(code);
        }
        return res;
    }
private:
    string hash(string& word) {
        vector<int> res(26, 0);
        for (char& c : word) {
            ++res[c-'a'];
        }
        string r = "";
        for (int i=0;i<26;++i) {
            if (res[i]) {
                r += string(1, 'a'+i) + to_string(res[i]);
            }
        }
        return r;
    }
};