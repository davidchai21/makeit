class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i=0;i<nums.size();i+=2) {
            res += nums[i];
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        const int d = 1e4;
        array<int, 20001> record;
        record.fill(0);
        for (int& num : nums) {
            ++record[num+d];
        }
        int r = 0;
        int res = 0;
        for (int i=0;i<20001;++i) {
            if (record[i]) {
                if (record[i]%2) {
                    res += (i-d)*((record[i]+1)/2-r);
                    r = 1-r;
                } else {
                    res += (i-d)*record[i]/2;
                }
            }
        }
        return res;
    }
};