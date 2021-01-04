class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string t = "";
        helper(digits, 0, res, t);
        return res;
    }
private:
    vector<vector<char>> dict = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    
    void helper(string& digits, int pos, vector<string>& res, string& t) {
        if (pos >= digits.size()) {
            res.push_back(t);
            return;
        }
        
        int index = digits[pos]-'0';
        for (int i=0;i<dict[index].size();++i) {
            t.push_back(dict[index][i]);
            helper(digits, pos+1, res, t);
            t.pop_back();
        }
    }
};