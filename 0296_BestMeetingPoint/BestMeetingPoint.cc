class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        int count = 0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) {
                    ++row[i];
                    ++col[j];
                    ++count;
                }
            }
        }
        int res = 0;
        int row_mid = findMedian(row, count);
        int col_mid = findMedian(col, count);
        return getSum(row, row_mid) + getSum(col, col_mid);
    }
private:
    int findMedian(vector<int>& nums, int count) {
        int c = 0;
        int index = 0;
        int limit = (count+1)/2;
        while (c < limit) {
            c += nums[index++];
        }
        return index-1;
    }
    
    int getSum(vector<int>& nums, int mid) {
        int sum = 0;
        for (int i=0;i<mid;++i) {
            sum += (mid-i)*nums[i];
        }
        for (int i=mid;i<nums.size();++i) {
            sum += (i-mid)*nums[i];
        }
        return sum;
    }
};