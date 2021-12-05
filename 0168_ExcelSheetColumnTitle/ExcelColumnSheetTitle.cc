class Solution {
public:
    string convertToTitle(int n) {
        if (n < 27) return string(1, 'A'+(n-1)%26);
        char tail = 'A' + (--n)%26;
        return convertToTitle(n/26) + string(1, tail);
    }
};