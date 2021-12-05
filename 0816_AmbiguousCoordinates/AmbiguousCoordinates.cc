class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> res;
        for (int i=2;i<n-1;++i) {
            vector<string> left = helper(s.substr(1, i-1));
            if (left.empty()) continue;
            vector<string> right = helper(s.substr(i, n-1-i));
            for (string& r : right) {
                for (string& l : left) {
                    res.push_back("("+l+", "+r+")");
                }
            }
        }
        return res;
    }
private:
    vector<string> helper(string s) {
        if (s == "0") return {s};
        int n = s.size();
        vector<string> res;
        if (s.front() != '0') res.push_back(s);
        else {
            if (!stoi(s.substr(1))) return {};
        }
        
        for (int i=1;i<n;++i) {
            if (stoi(s.substr(i)) && s.back() != '0') {
                if (i > 1 && (stoi(s.substr(0, i)) == 0 || s.front() == '0')) break;
                res.push_back(s.substr(0,i)+"."+s.substr(i));
            } else break;
        }
        return res;
    }
};