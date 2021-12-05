class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> record(n, 0);
        record.front() = chalk.front();
        for (int i=1;i<n;++i) {
            record[i] += record[i-1]+chalk[i];
        }
        k %= record.back();
        return helper(record, k);
    }
private:
    int helper(vector<long>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid] <= k) left = mid+1;
            else right = mid;
        }
        return left;
    }
};

// Shorter:

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = accumulate(chalk.begin(), chalk.end(), 0L);
        k %= sum;
        int index = 0;
        while (k >= chalk[index]) {
            k -= chalk[index++];
        }
        return index;
    }
};