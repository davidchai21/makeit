class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dic(256,0);
        for (char& c : s) ++dic[c];
        for (char& c : t) --dic[c];
        for (int& n : dic) {
            if (n) return false;
        }
        return true;
    }
};