class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        
        string res = "";
        for (char& c : num) {
            while (!res.empty() && k && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        
        while (k--) {
            res.pop_back();
        }
        
        int index = 0;
        while (index < res.size() && res[index] == '0') ++index;
        return index == res.size() ? "0" : res.substr(index);
    }
};