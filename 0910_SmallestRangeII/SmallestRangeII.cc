class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = A.back()-A.front();
        for (int i=0;i<A.size()-1;++i) {
            int high = max(A[i]+K, A.back()-K);
            int low = min(A[i+1]-K, A.front()+K);
            res = min(high-low, res);
        }
        return res;
    }
};