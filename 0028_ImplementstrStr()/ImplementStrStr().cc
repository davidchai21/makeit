class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size();
        int n = needle.size();
        for (int i=0;i<=m-n;++i) {
            if (check(haystack, i, needle)) return i;
        }
        return -1;
    }
private:
    bool check(string& h, int index, string& needle) {
        for (int i=0;i<needle.size();++i) {
            if (h[index+i] != needle[i]) return false;
        }
        return true;
    } 
};