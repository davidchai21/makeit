class Solution {
public:
    int uniqueLetterString(string s) {
        vector<pair<int,int>> dic(26, {-1,-1});
        int n = s.size();
        int res = 0;
        for (int i=0;i<n;++i) {
            int pos = s[i]-'A';
            res += (dic[pos].second-dic[pos].first)*(i-dic[pos].second);
            dic[pos].first = dic[pos].second;
            dic[pos].second = i;
        }
        for (int i=0;i<26;++i) {
            res += (n-dic[i].second)*(dic[i].second-dic[i].first);
        }
        return res;
    }
};