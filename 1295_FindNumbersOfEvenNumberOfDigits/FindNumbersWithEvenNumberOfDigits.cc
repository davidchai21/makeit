class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int& num : nums) {
            if (helper(num)%2 == 0) ++res;
        }
        return res;
    }
private:
    inline int helper(int n) {
        int res = 0;
        while (n) {
            n /= 10;
            ++res;
        }
        return res;
    }
};