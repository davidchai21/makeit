class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int pre = values.front();
        int res = 0;
        for (int i=1;i<values.size();++i) {
            res = max(res, pre + values[i]-i);
            pre = max(pre, values[i]+i);
        }
        return res;
    }
};