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