class Solution {
public:
    bool checkOnesSegment(string s) {
        int index = 0, n = s.size();
        while (index < n && s[index] == '1') ++index;
        while (index < n && s[index] == '0') ++index;
        return index == n;
    }
};