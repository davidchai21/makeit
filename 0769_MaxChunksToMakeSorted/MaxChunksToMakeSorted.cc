class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int right = 0;
        int n = arr.size();
        int res = 0;
        int index = 0;
        while (index < n) {
            if (index < n) right = arr[index];
            while (index <= right) {
                right = max(right, arr[index++]);
            }
            ++res;
        }
        return res;
    }
};