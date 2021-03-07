class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n-1);
        char digit = s.front();
        int count = 1;
        string res = "";
        for (int i=1;i<s.size();++i) {
            if (s[i] == digit) ++count;
            else {
                res += to_string(count) + string(1, digit);
                count = 1;
                digit = s[i];
            }
        }
        res += to_string(count) + string(1, digit);
        return res;
    }
};