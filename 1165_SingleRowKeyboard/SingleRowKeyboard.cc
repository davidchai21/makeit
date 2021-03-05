class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> keys(26, 0);
        for (int i=0;i<26;++i) {
            keys[keyboard[i]-'a'] = i;
        }
        
        int res = 0;
        char pre = keyboard.front();
        for (char& c : word) {
            res += abs(keys[c-'a'] - keys[pre-'a']);
            pre = c;
        }
        return res;
    }
};