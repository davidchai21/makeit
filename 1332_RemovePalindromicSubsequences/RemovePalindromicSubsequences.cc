class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        else if (isPalindrome(s)) return 1;
        return 2;
    }
private:
    inline bool isPalindrome(string& s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};