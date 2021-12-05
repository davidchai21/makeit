class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res;
        vector<string> t;
        helper(s, res, t, 0);
        return res;
    }
private:
    void helper(string& s, vector<string>& res, vector<string>& t, int index) {
        if (index == s.size()) {
            if (t.size() == 4) {
                res.push_back(t[0]+"."+t[1]+"."+t[2]+"."+t[3]);
            }
            return;
        }
        if (t.size() >= 4) return;
        
        if (s[index] == '0') {
            t.push_back("0");
            helper(s, res, t, index+1);
            t.pop_back();
        } else {
            for (int i=1;i<4 && index+i<=s.size();++i) {
                string str = s.substr(index, i);
                if (stoi(str) > 255) continue;
                t.push_back(str);
                helper(s, res, t, index+i);
                t.pop_back();
            }
        }
    }
};