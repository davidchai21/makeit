class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = max(arrays[1].back()-arrays[0].front(), arrays[0].back()-arrays[1].front());
        int high = max(arrays[0].back(), arrays[1].back());
        int low = min(arrays[0].front(), arrays[1].front());
        for (int i=2;i<arrays.size();++i) {
            res = max(res, max(high-arrays[i].front(), arrays[i].back()-low));
            high = max(high, arrays[i].back());
            low = min(low, arrays[i].front());
        }
        return res;
    }
};