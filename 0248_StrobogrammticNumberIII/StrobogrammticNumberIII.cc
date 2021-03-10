class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = helper(low, high, "", 0);
        res = helper(low, high, "0", res);
        res = helper(low, high, "1", res);
        res = helper(low, high, "8", res);
        return res;
    }
private:
    vector<pair<char, char>> dic = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    
    bool lessThan(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return s1.size() < s2.size();
        for (int i=0;i<s1.size();++i) {
            if (s1[i] < s2[i]) return true;
            else if (s1[i] > s2[i]) return false;
        }
        return true;
    }
    
    int helper(const string& low, const string& high, string s, int res) {
        if (s.size() > high.size()) return res;
        if (lessThan(low, s) && lessThan(s, high)) {
            if (s.size() == 1 || s.size() > 1 && s.front() != '0') ++res;
        }
        
        for (auto it = dic.begin(); it != dic.end(); ++it) {
            res = helper(low, high, string(1,it->first)+s+string(1,it->second), res);
        }
        return res;
    }
};