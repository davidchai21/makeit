class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum = 0L;
        int min_num = nums.front();
        for (int & num : nums) {
            sum += num;
            min_num = min(min_num, num);
        }
        return sum - (long)min_num*nums.size();
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int k = *min_element(nums.begin(), nums.end());
        int sum = 0;
        for (int & num : nums) {
            sum += num - k;
        }
        return sum;
    }
};