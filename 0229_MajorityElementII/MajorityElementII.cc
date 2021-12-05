class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int num1 = 0, num2 = 0;
        for (int& num : nums) {
            if (num == num1) ++count1;
            else if (num == num2) ++count2;
            else if (!count1) {
                count1 = 1;
                num1 = num;
            } else if (!count2) {
                count2 = 1;
                num2 = num;
            } else {
                --count1;
                --count2;
            }
        }
        
        count1 = 0, count2 = 0;
        for (int& num : nums) {
            if (num == num1) ++count1;
            else if (num == num2) ++count2;
        }
        
        vector<int> res;
        if (count1 > nums.size()/3) res.push_back(num1);
        if (count2 > nums.size()/3) res.push_back(num2);
        return res;
    }
};