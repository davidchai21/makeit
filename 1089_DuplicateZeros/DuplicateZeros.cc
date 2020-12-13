class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int tail = size + count(arr.begin(), arr.end(), 0) - 1;
        for (int i=0;i<size;++i,--tail) {
            if (tail<size) arr[tail] = arr[size-1-i];
            if (!arr[size-i-1] && --tail<size) arr[tail] = 0;
        }
    }
};