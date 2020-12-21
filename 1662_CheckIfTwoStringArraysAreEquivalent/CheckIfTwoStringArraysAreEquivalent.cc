class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();
        int i=0, ii=0, j=0, jj=0;
        while (i<m && j<n) {
            if (word1[i][ii] != word2[j][jj]) return false;
            ++ii;
            ++jj;
            if (ii>=word1[i].size()) {
                ++i;
                ii=0;
            }
            if (jj>=word2[j].size()) {
                ++j;
                jj=0;
            }
        }
        return i==word1.size() && j==word2.size();
    }
};