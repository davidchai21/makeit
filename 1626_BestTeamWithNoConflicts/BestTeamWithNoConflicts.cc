class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> record(n);   // score, age
        for (int i = 0;i<n;++i) {
            record[i] = {scores[i], ages[i]};
        }
        sort(record.begin(), record.end(), [](const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.second > rhs.second || lhs.second == rhs.second && lhs.first > rhs.first;
        });
        
        int res = 0;
        vector<int> total(n, 0);
        for (int i=0;i<n;++i) {
            total[i] = record[i].first;
            for (int j=i-1;j>=0;--j) {
                if (record[j].first >= record[i].first) {
                    total[i] = max(record[i].first + total[j], total[i]);
                }
            }
            res = max(total[i], res);
        }
        return res;
    }
};