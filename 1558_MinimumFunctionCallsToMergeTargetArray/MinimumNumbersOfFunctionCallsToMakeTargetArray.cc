class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int index = 0;
        int sum = 0;
        int score = 0;
        while (index < k) {
            sum += calories[index++];
        }
        do {
            if (sum < lower) --score;
            else if (sum > upper) ++score;
            if (index < calories.size()) sum += calories[index] - calories[index-k];
            ++index;
        } while (index <= calories.size());
        return score;
    }
};

// Builtin function -- bit manipulation:

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int maxLen = 0;
        for (int& num : nums) {
            if (num) {
                res += __builtin_popcount(num);
                maxLen = max(maxLen, bits - __builtin_clz(num));
            }
        }
        return res + maxLen;
    }
private:
    const int bits = 31;
};