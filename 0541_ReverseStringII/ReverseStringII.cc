class Solution {
public:
    string reverseStr(string s, int k) {
        int len = 0;
        bool flag = true;
        for (int i=0;i<s.size();++i) {
            if (++len == k) {
                if (flag) {
                    helper(s, i+1-k, i);
                }
                len = 0;
                flag = !flag;
            }
        }
        if (flag) helper(s, s.size()-len, s.size()-1);
        return s;
    }
private:
    void helper(string& s, int a, int b) {
        while (a < b) {
            swap(s[a++], s[b--]);
        }
    }
};