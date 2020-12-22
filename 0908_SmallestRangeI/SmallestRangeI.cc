class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        auto largest = max_element(A.begin(), A.end());
        auto smallest = min_element(A.begin(), A.end());
        return max(0, *largest-*smallest-2*K);
    }
};