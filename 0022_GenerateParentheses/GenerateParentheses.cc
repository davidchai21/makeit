class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string t = "";
        helper(n, t, res, 0);
        return res;
    }
private:
    void helper(int n, string& t, vector<string>& res, int count) {
        if (n<0 || count<0) return;
        if (!count && !n) {
            res.push_back(t);
            return;
        }
        
        t.push_back('(');
        helper(n-1, t, res, count+1);
        t.pop_back();
        t.push_back(')');
        helper(n, t, res, count-1);
        t.pop_back();
    }
};