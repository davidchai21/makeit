class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> index;
        for (int i=0;i<s1.size();++i) {
            if (s1[i] != s2[i]) index.push_back(i);
        }
        if (index.size() == 1 || index.size() > 2) return false;
        if (index.size() == 2) {
            if (s1[index[0]] != s2[index[1]] || s1[index[1]] != s2[index[0]]) return false;
        }
        return true;
    }
};