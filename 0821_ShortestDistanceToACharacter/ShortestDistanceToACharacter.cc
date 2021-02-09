class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size(), INT_MAX);
        for (int i=0;i<s.size();++i) {
            if (s[i]==c) res[i] = 0;
        }
        for (int i=0;i<s.size();++i) {
            if (s[i]==c) helper(res, i);
        }
        return res;
    }
private:
    void helper(vector<int>& res, int index) {
        int len = 1;
        int diff = 1;
        while (index-diff>=0 && res[index-diff] > len) {
            res[index-diff] = len;
            ++len;
            ++diff;
        }
        len = 1;
        diff = 1;
        while (index+diff < res.size() && res[index+diff] > len) {
            res[index+diff] = len++;
            ++diff;
        }
    }
};

// Better:

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), pos = -n;
        vector<int> res(n, n);
        for (int i=0;i<n;++i) {
            if (s[i]==c) pos = i;
            res[i] = i-pos;
        }
        for (int i=pos-1;i>=0;--i) {
            if (s[i]==c) pos = i;
            res[i] = min(res[i], pos-i);
        }
        return res;
    }
};