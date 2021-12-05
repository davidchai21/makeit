class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s(jewels.begin(), jewels.end());
        int res = 0;
        for (char& c : stones) {
            if (s.find(c) == s.end()) continue;
            ++res;
        }
        return res;
    }
};

// Using vector:

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> record(256, false);
        for (char& c : jewels) record[c] = true;
        int res = 0;
        for (char& c : stones) {
            if (record[c]) ++res;
        }
        return res;
    }
};