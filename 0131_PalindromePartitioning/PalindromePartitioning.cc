class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int n = s.size();
        if (!n) return res;
        vector<vector<bool>> table(n, vector<bool>(n, true));
        for (int i=n-1;i>=0;--i) {
            for (int j=i+1;j<n;++j) {
                table[i][j] = table[i+1][j-1] && s[i]==s[j];
            }
        }
        vector<string> t;
        helper(res, table, t, s, 0);
        return res;
    }
private:
    void helper(vector<vector<string>>& res, vector<vector<bool>>& table, vector<string>& t, string& s, int pos) {
        if (pos >= s.size()) {
            res.push_back(t);
            return;
        }
        for (int i=pos;i<s.size();++i) {
            if (table[pos][i]) {
                t.push_back(s.substr(pos, i+1-pos));
                helper(res, table, t, s, i+1);
                t.pop_back();
            }
        }
    }
};