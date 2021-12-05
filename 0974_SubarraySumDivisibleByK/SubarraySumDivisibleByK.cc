class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K, 0);
        count[0] = 1;
        int sum = 0;
        int res = 0;
        for (int& a : A) {
            sum = ((sum+a)%K+K)%K;
            res += count[sum]++;
        }
        return res;
    }
};