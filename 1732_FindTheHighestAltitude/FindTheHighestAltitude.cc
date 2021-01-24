class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int sum = 0;
        for (int& h : gain) {
            sum += h;
            res = max(res, sum);
        }
        return res;
    }
};