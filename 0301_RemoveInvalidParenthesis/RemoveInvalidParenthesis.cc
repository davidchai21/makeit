class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char& c : s) {
            if (c=='(') {
                ++left;
            } else if (c==')') {
                if (left) --left;
                else ++right;
            }
        }
        unordered_set<string> res;
        dfs(s, "", 0, left, right, 0, res);
        return vector<string>(res.begin(), res.end());
    }
private:
    void dfs(const string& s, string str, int index, int left, int right, int match, unordered_set<string>& res) {
        if (index == s.size()) {
            if (!left && !right && !match) {
                res.insert(str);
            }
            return;
        }
        
        if (isalpha(s[index])) {
            dfs(s, str+s[index], index+1, left, right, match, res);
        } else {
            if (s[index]=='(') {
                if (left) {
                    dfs(s, str, index+1, left-1, right, match, res);
                }
                dfs(s, str+'(', index+1, left, right, match+1, res);
            } else {
                if (right) {
                    dfs(s, str, index+1, left, right-1, match, res);
                }
                if (match) {
                    dfs(s, str+')', index+1, left, right, match-1, res);
                }
            }
        }
    }
};