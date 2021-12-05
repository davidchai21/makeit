class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) ++left;
            while (left < right && !isVowel(s[right])) --right;
            swap(s[left++], s[right--]);
        }
        return s;
    }
private:
    inline bool isVowel(char& t) {
        char c = tolower(t);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};