class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> s({'a','e','i','o','u'});
        string res = "";
        for (int i=0;i<S.size();++i) {
            if (s.find(S[i])==s.end()) res += S[i];
        }
        return res;
    }
};