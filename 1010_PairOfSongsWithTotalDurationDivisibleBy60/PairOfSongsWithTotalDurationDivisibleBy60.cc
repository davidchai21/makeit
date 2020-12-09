class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> t(60,0);
        for (int tim: time) {
            ++t[tim%60];
        }
        int res = 0;
        res += t[0]*(t[0]-1)/2 + t[30]*(t[30]-1)/2;
        for (int i=1;i<30;++i) {
            res += t[i]*t[60-i];
        }
        return res;
    }
};