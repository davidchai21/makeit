class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for (int i=2;i<=numRows;++i) {
            vector<int> t(i,1);
            for (int j=1;j<i-1;++j) {
                t[j] = res.back()[j-1]+res.back()[j];
            }
            res.push_back(t);
        }
        return res;
    }
};