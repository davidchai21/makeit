class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int> count(80000, 0);
        for (int& k : A) {
            ++count[k];
        }
        int res = 0;
        int left = 0;
        for (int i=0;i<80000;++i) {
            if (count[i] > 1) {
                res -= (count[i]-1)*i;
                left += count[i]-1;
            } else if (left && !count[i]) {
                res += i;
                --left;
            }
            if (i > 40000 && !left) break;
        }
        return res;
    }
};