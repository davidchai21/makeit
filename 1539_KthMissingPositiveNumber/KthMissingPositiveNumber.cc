class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        for (;i<arr.size();++i) {
            int miss = arr[i]-i-1;
            if (miss >= k) break;
        }
        if (i==0) return k;
        return k+i;
    }
};

// Binary Search:

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (arr[mid]-mid-1 < k) left = mid+1;
            else right = mid;
        }
        return left + k;
    }
};