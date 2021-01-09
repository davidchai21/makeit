class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0, right = 0;
        while (right < n) {
            while (right < n && s[right] != ' ') ++right;
            helper(s, left, right-1);
            left = ++right;
        }
        return s;
    }
private:
    void helper(string& s, int a, int b) {
        while (a < b) swap(s[a++], s[b--]);
    }
};