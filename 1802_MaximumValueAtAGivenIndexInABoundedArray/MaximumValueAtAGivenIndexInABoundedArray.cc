class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = index, right = n-1-index;
        long start = 1, end = maxSum;
        while (start + 1 < end) {
            long mid = start + (end - start)/2;
            long x = helper(mid, left, right);
            if (x == maxSum) return mid;
            else if (x < maxSum) start = mid;
            else end = mid;
        }
        
        if (helper(end, left, right) <= maxSum) return end;
        return start;
    }
private:
    long helper(long mid, int left, int right) {
        long sum = mid*mid;
        if (mid-1>=left) {
            long k = mid-1-left;
            sum -= k*(k+1)/2;
        } else {
            sum += left-mid+1;
        }
        if (mid-1 >= right) {
            long k = mid-1-right;
            sum -= k*(k+1)/2;
        } else {
            sum += right-mid+1;
        }
        return sum;
    }
};