class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> dic1(256, 0), dic2(256, 0);
        for (int i=0;i<s.size();++i) {
            if (dic1[s[i]] != dic2[t[i]]) return false;
            dic1[s[i]] = i+1;
            dic2[t[i]] = i+1;
        }
        return true;
    }
};