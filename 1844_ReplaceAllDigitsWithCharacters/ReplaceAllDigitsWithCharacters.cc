class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for (int i=0;i<n;i+=2) {
            if (i+1 < n) s[i+1] = s[i]+(s[i+1]-'0');
        }
        return s;
    }
};