class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res = "";
        int i = 0, j = 0;
        int m = word1.size(), n = word2.size();
        while (i < m && j < n) {
            if (word1[i] > word2[j]) {
                res += word1[i++];
            } else if (word1[i] < word2[j]) {
                res += word2[j++];
            } else {
                if (word1.substr(i).compare(word2.substr(j)) >= 0) {
                    res += word1[i++];
                } else {
                    res += word2[j++];
                }
            }
        }
        if (i < m) res += word1.substr(i);
        if (j < n) res += word2.substr(j);
        return res;
    }
};