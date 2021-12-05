class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> record(nums.size());
        int start = 0;
        int count = 1;
        for (int i=0;i<nums.size();++i) {
            record[i] = {1, -1};
            for (int j=0;j<i;++j) {
                if (nums[i]%nums[j] == 0) {
                    if (record[j].first+1 > record[i].first) {
                        record[i] = {record[j].first+1, j};
                    }
                }
            }
            if (count < record[i].first) {
                start = i;
                count = record[i].first;
            }
        }
        
        vector<int> res(count);
        int index = 0;
        do {
            res[index++] = nums[start];
            start = record[start].second;
        } while (start != -1);
        return res;
    }
};