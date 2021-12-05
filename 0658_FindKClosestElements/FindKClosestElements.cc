class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res(k);
        int n = arr.size();
        int right = lower_bound(arr, x);
        int left = max(right-k, 0);
        right = min(n-1, right+k);
        while (right-left+1>k) {
            if (arr[right]-x < x-arr[left]) ++left;
            else --right;
        }
        return vector<int>(arr.begin()+left, arr.begin()+right+1);
    }
private:
    int lower_bound(vector<int>& arr, int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right-left)/2;
            if (arr[mid] >= x) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};

// Better Binary Search:

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-k;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (x-arr[mid] > arr[mid+k]-x) left = mid+1;
            else right = mid;
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
};