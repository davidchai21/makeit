class Solution {
public:
    int compareVersion(string version1, string version2) {
        int left = 0, right = 0;
        int m = version1.size();
        int n = version2.size();
        while (left < m || right < n) {
            int num1 = 0, num2 = 0;
            while (left < m && version1[left]!='.') {
                num1 = num1*10+version1[left++]-'0';
            }
            if (left < m) ++left;
            while (right < n && version2[right]!='.') {
                num2 = num2*10+version2[right++]-'0';
            }
            if (right < n) ++right;
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
        }
        return 0;
    }
};