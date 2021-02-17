class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(S, res, 0);
        return res;
    }
private:
    void helper(string& s, vector<string>& res, int index) {
        if (index >= s.size()) {
            res.push_back(s);
            return;
        }
        
        if (isdigit(s[index])) helper(s, res, index+1);
        else {
            s[index] = tolower(s[index]);
            helper(s, res, index+1);
            s[index] = toupper(s[index]);
            helper(s, res, index+1);
        }
    }
};

// XOR Trick:

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(S, res, 0);
        return res;
    }
private:
    void helper(string& s, vector<string>& res, int index) {
        if (index >= s.size()) {
            res.push_back(s);
            return;
        }
        
        helper(s, res, index+1);
        if (isalpha(s[index])) {
            s[index] ^= 32;
            helper(s, res, index+1);
            s[index] ^= 32;
        }
    }
};