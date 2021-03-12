class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size()-1;
        while (index >= 0 && digits[index] == 9) {
            digits[index--] = 0;
        }
        if (index >= 0) {
            ++digits[index];
            return digits;
        }
        digits.front() = 1;
        digits.push_back(0);
        return digits;
    }
};