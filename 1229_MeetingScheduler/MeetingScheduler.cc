class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        sort(slots2.begin(), slots2.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int left = 0, right = 0;
        int m = slots1.size();
        int n = slots2.size();
        while (left < m && right < n) {
            int start = max(slots1[left][0], slots2[right][0]);
            int end = min(slots1[left][1], slots2[right][1]);
            if (end - start >= duration) return {start, start+duration};
            if (slots1[left][1] < slots2[right][1]) ++left;
            else ++right;
        }
        return {};
    }
};