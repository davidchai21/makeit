class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int right = 0;
        for (int i=0;i<light.size();++i) {
            right = max(right, light[i]-1);
            if (right == i) ++res;
        }
        return res;
    }
};