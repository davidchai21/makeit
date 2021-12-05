class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;
        while (left + 1 < right) {
            int mid = left+(right-left)/2;
            long sum = helper(mid);
            if (sum <= n) left = mid;
            else right = mid-1;
        }
        return helper(right) <= n ? right : left;
    }
private:
    long helper(int mid) {
        return (long)mid*(mid+1)/2L;
    }
};

// Math: 

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2L*n+0.25)-0.5);
    }
};