class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = words.size();
        int l = -1;
        int r = -1;
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
            if (it->compare(word1) == 0) l = it - words.begin();
            else if (it->compare(word2) == 0) r = it - words.begin();
            else continue;
            if (l != -1 && r != -1 && abs(l-r)<res) res = abs(l-r);
        }
        return res;
    }
};