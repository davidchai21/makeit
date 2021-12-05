class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<pair<bool, vector<int>>> dp(n+1);
        dp[0] = {true, {}};
        
        for (int i=1;i<=n;++i) {
            for (int j=0;j<i;++j) {
                if (dp[j].first && st.find(s.substr(j, i-j)) != st.end()) {
                    dp[i].first = true;
                    dp[i].second.push_back(j);
                }
            }
        }
        vector<string> res;
        vector<int> t;
        helper(s, res, t, dp, n);
        return res;
    }
private:
    string getStr(string& s, vector<int>& t) {
        int base = 0;
        string res = "";
        for (int i=t.size()-1;i>=0;--i) {
            if (!res.empty()) res += " ";
            res += s.substr(base, t[i]-base);
            base = t[i];
        }
        if (!res.empty()) res += " ";
        res += s.substr(base, s.size()-base);
        return res;
    }
    
    void helper(string& s, vector<string>& res, vector<int>& t, vector<pair<bool, vector<int>>>& dp, int index) {
        if (index == 0) {
            res.push_back(getStr(s, t));
            return;
        }
        
        for (int& k : dp[index].second) {
            t.push_back(k);
            helper(s, res, t, dp, k);
            t.pop_back();
        }
    }
};