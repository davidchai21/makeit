class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> record(n, -1);
        int res = 0;
        for (int i=0;i<n;++i) {
            if (record[i] != -1) continue;
            int count = 0;
            int index = i;
            while (record[index] == -1) {
                record[index] = i;
                ++count;
                index = nums[index];
            }
            res = max(res, count);
        }
        return res;
    }
};

// O(1) space:

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i=0;i<nums.size();++i) {
            if (nums[i] < 0) continue;
            int count = 0;
            int index = i;
            while (nums[index] >=0) {
                nums[index] = -nums[index]-1;
                index = -1-nums[index];
                ++count;
            }
            res = max(res, count);
        }
        return res;
    }
};