class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int index = 0;
        int cur = 0;
        int n = s.size();
        while (index < n) {
            while (cur < n && s[cur] == ' ') ++cur;
            if (cur >= n) break;
            if (index) s[index++] = ' ';
            int right = cur+1;
            while (right < n && s[right] != ' ') ++right;
            int l = cur, r = --right;
            while (l < r) {
                swap(s[l++], s[r--]);
            }
            while (cur<=right) s[index++] = s[cur++];
        }
        s.resize(index);
        return s;
    }
};