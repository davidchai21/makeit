class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int num = -1;
        for (int i=arr.size()-1;i>=0;--i) {
            int t = arr[i];
            arr[i] = num;
            num = max(num, t);
        }
        return arr;
    }
};