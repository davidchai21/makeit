class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        if (firstList.empty() || secondList.empty()) return res;
        int i = 0, j = 0;
        int m = firstList.size(), n = secondList.size();
        while (i<m && j<n) {
            int start = max(firstList[i].front(), secondList[j].front());
            int end = min(firstList[i].back(), secondList[j].back());
            if (start <= end) res.push_back({start, end});
            if (firstList[i].back() < secondList[j].back()) ++i;
            else ++j;
        }
        return res;
    }
};