class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        vector<int> t;
        for (int i=1;i<=rowIndex;++i) {
            res.swap(t);
            res.resize(i+1);
            res[0] = res.back() = 1;
            for (int j=1;j<i;++j) {
                res[j] = t[j] + t[j-1];
            }
        }
        return res;
    }
};