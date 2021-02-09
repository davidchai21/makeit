class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), left = 0, right = 0;
        vector<int> pre(n, -1), suf(n, -1);
        int sum = 0;
        int shortest = -1;
        for (;right < n;++right) {
            sum += arr[right];
            while (left<=right && sum > target) sum -= arr[left++];
            if (sum == target) {
                if (shortest == -1) shortest = right+1-left;
                else shortest = min(shortest, right+1-left);
            }
            pre[right] = shortest;
        }
        sum = 0;
        shortest = -1;
        left = n-1;
        right = n-1;
        for (;left>=0;--left) {
            sum += arr[left];
            while (right >= left && sum > target) sum -= arr[right--];
            if (sum == target) {
                if (shortest == -1) shortest = right+1-left;
                else shortest = min(shortest, right+1-left);
            }
            suf[left] = shortest;
        }
        int res = -1;
        for (int i=0;i<n-1;++i) {
            if (pre[i] != -1 && suf[i+1] != -1) {
                if (res == -1) res = pre[i]+suf[i+1];
                else res = min(res, pre[i]+suf[i+1]);
                if (res == 2) return res;
            }
        }
        return res;
    }
};