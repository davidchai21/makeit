class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        int l = -1;
        int r = -1;
        for (int i=0;i<words.size();++i) {
            if (words[i] == word1) {
                l = word1 == word2 ? r : i;
            }
            if (words[i] == word2) r = i;
            if (l != -1 && r != -1) res = min(res, abs(l-r));
        }
        return res;
    }
};