class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> count(26, 0);
        for (string& word : words) {
            for (char& c : word) ++count[c-'a'];
        }
        for (int i=0;i<26;++i) {
            if (count[i] % n) return false;
        }
        return true;
    }
};