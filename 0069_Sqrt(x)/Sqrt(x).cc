// Newton's method:

class Solution {
public:
    int mySqrt(int x) {
        double k = x;
        double y = (1.0+k)/2;
        while (abs(y-k) >= 0.5) {
            k = y;
            y = (k+x/k)/2.0;
        }
        return y;
    }
};

// Binary Search:

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        long p = 0;
        int left = 0, right = x/2;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            p = (long)mid*mid;
            if (p > x) right = mid-1;
            else left = mid;
        }
        if ((long)right*right <= x) return right;
        return left;
    }
};