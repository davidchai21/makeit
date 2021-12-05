class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> dic(26, 0);
        for (const char& c : magazine) {
            ++dic[c-'a'];
        }
        for (const char& c : ransomNote) {
            if (--dic[c-'a'] < 0) return false;
        }
        return true;
    }
};