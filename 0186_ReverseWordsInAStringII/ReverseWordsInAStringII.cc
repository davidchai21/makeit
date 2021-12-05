class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int left = 0, right = 0;
        int n = s.size();
        while (left < n) {
            right = left;
            while (right < n && s[right]!=' ') ++right;
            helper(s, left, right-1);
            left = right+1;
        }
    }
private:
    void helper(vector<char>& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};