class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int level = log2(label);
        res.push_back(label);
        while (level) {
            int sum = 3*pow(2, --level);
            label = sum - label/2 - 1;
            res.push_back(label);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};