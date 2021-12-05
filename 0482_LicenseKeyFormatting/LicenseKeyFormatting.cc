class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int count = 0;
        string res = "";
        for (int i=S.size()-1;i>=0;--i) {
            if (S[i]=='-') continue;
            else {
                res.push_back(toupper(S[i]));
                ++count;
                if (count == K) {
                    res.push_back('-');
                    count = 0;
                }
            }
        }
        if (res.back() == '-') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};