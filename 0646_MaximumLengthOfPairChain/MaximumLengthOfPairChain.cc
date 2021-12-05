class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> record(pairs.size(), 1);
        int res = 1;
        for (int i=pairs.size()-2;i>=0;--i) {
            for (int j=pairs.size()-1;j>i && pairs[j].front() > pairs[i].back();--j) {
                record[i] = max(record[i], record[j]+1);
            }
            res = max(res, record[i]);
        }
        return res;
    }
};

// Greedy: 56ms