class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> record(n, {1,1});
        int len = 0, res = 0;
        for (int i=0;i<n;++i) {
            int l = 1, count = 1;
            for (int j=0;j<i;++j) {
                if (nums[i] > nums[j]) {
                    if (record[j].first >= l) {
                        l = record[j].first+1;
                        count = record[j].second;
                    } else if (record[j].first == l-1) {
                        count += record[j].second;
                    }
                }
            }
            record[i] = {l, count};
            if (len < l) {
                len = l;
                res = count;
            } else if (len == l) {
                res += count;
            }
        }
        return res;
    }
};