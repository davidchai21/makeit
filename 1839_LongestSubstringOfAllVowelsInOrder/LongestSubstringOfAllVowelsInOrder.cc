class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int res = 0;
        vector<int> record(5, 0);
        int left = 0;
        int n = word.size();
        for (int i=0;i<n;++i) {
            if (i && word[i] < word[i-1]) {
                if (record[0] && record[1] && record[2] && record[3] && record[4]) res = max(res, i-left);
                fill(record.begin(), record.end(), 0);
                left = i;
            }
            helper(record, word[i]);
        }
        if (record[0] && record[1] && record[2] && record[3] && record[4]) res = max(res, n-left);
        return res;
    }
private:
    void helper(vector<int>& r, char& c) {
        switch (c) {
            case 'a':
                ++r[0];
                break;
            case 'e':
                ++r[1];
                break;
            case 'i':
                ++r[2];
                break;
            case 'o':
                ++r[3];
                break;
            case 'u':
                ++r[4];
                break;
            default:
                break;
        }
    }
};

// Another: 

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int count = 1;
        int res = 0;
        int len = 1;
        int n = word.size();
        for (int i=1;i<n;++i) {
            if (word[i] == word[i-1]) {
                ++len;
            } else if (word[i] > word[i-1]) {
                ++len;
                ++count;
            } else {
                len = 1;
                count = 1;
            }
            if (count == 5) {
                res = max(res, len);
            }
        }
        return res;
    }
};