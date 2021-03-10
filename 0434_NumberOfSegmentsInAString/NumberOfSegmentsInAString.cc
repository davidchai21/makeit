class Solution {
public:
    int countSegments(string s) {
        int index = 0;
        int n = s.size();
        int count = 0;
        while (index < n) {
            while (index < n && s[index] == ' ') ++index;
            if (index == n) break;
            ++count;
            while (index < n && s[index] != ' ') ++index;
        }
        return count;
    }
};