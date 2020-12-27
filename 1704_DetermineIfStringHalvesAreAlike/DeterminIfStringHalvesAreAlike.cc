class Solution {
public:
    bool halvesAreAlike(string s) {
        int size = s.size()/2;
        int left = 0, right = 0;
        for (int i=0;i<size;++i) {
            if (isVowel(tolower(s[i]))) ++left;
            if (isVowel(tolower(s[i+size]))) ++right;
        }
        return left == right;
    }
private:
    bool isVowel(char a) {
        return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
    }
};