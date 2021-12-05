class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> record(n, 0);
        for (int i=n-2;i>=0;--i) {
            record[i] = 1-s[i+1]+'0'+record[i+1];
        }
        
        int res = record.front();
        int left = 0;
        for (int i=0;i<n;++i) {
            if (s[i] == '1') ++left;
            res = min(res, left+record[i]);
        }
        return res;
    }
};

// Better O(1) space:

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flip_one = 0, flip = 0;
        for (char& c : s) {
            if (c == '0') ++flip;
            else ++flip_one;
            flip = min(flip, flip_one);
        }
        return flip;
    }
};