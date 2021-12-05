class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int>& lhs, const vector<int>& rhs){
            return lhs.front() > rhs.front() || lhs.front() == rhs.front() && lhs.back() > rhs.back();
        });
        int n = envelopes.size();
        vector<int> record(n, 0);
        int res = 0;
        for (int i=n-1;i>=0;--i) {
            int ans = 1;
            for (int j=i+1;j<n;++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    ans = max(ans, 1+record[j]);
                }
            }
            record[i] = ans;
            res = max(res, ans);
        }
        return res;
    }
};

// O(nlogn) solution:

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs.front() < rhs.front() || lhs.front() == rhs.front() && lhs.back() > rhs.back();
        });
        vector<int> res;
        for (const vector<int>& e : envelopes) {
            auto it = lower_bound(res.begin(), res.end(), e.back());
            if (it == res.end()) {
                res.push_back(e.back());
            } else {
                *it = e.back();
            }
        }
        return res.size();
    }
};