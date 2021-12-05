class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        int left = 0, right = 0;
        while (left < n-1) {
            while (left < n-1 && arr[left] == arr[left+1]) ++left;
            right = left+1;
            while (right < n && arr[right] > arr[right-1]) ++right;
            int mid = right-1;
            while (right < n && arr[right] < arr[right-1]) ++right;
            --right;
            if (mid > left && right > mid) res = max(res, right+1-left);
            left = right;
        }
        return res;
    }
};