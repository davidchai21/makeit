class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size()+1;
        return n*arr.front() + (long)n*(n-1)/2*(arr.back()-arr.front())/(n-1) - accumulate(arr.begin(), arr.end(), 0);
    }
};

// Binary Search:

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        int k = (arr.back() - arr.front())/(int)arr.size();
        while (left < right) {
            int mid = left+(right-left)/2;
            if (arr[mid] != arr.front() + mid*k) right = mid;
            else left = mid+1;
        }
        return arr.front()+left*k;
    }
};