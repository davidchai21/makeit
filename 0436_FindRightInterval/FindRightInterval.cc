class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> record(n);
        for (int i=0;i<n;++i) {
            record[i].first = intervals[i].front();
            record[i].second = i;
        }
        sort(record.begin(), record.end(), [](const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.first < rhs.first;
        });
        vector<int> res(n, -1);
        for (int i=0;i<n;++i) {
            res[i] = lower_bound(record, intervals[i].back());
        }
        return res;
    }
private:
    int lower_bound(vector<pair<int, int>>& record, int endTime) {
        int left = 0, right = record.size();
        while (left < right) {
            int mid = left+(right-left)/2;
            if (record[mid].first == endTime) return record[mid].second;
            else if (record[mid].first < endTime) left = mid+1;
            else right = mid;
        }
        return left == record.size() ? -1 : record[left].second;
    }
};