class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> record(256, 0);
        int count = 0;
        for (char& c:s) {
            if (++record[c]%2) ++count;
            else --count;
        }
        return count < 2;
    }
};