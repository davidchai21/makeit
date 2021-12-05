class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for (vector<int>& range : ranges) {
            if (range.front() > left) return false;
            left = max(left, range.back()+1);
        }
        return left > right;
    }
};

// O(n) 

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> record(52, 0);
        for (vector<int>& range : ranges) {
            ++record[range.front()];
            --record[range.back()+1];
        }
        for (int i=1;i<52;++i) {
            record[i] += record[i-1];
        }
        for (int i=left;i<=right;++i) {
            if (!record[i]) return false;
        }
        return true;
    }
};