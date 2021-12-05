class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b){
            string sa = to_string(a);
            string sb = to_string(b);
            return (sa+sb).compare(sb+sa) > 0;
        });
        
        if (nums.front() == 0) return "0";
        string res = "";
        for (int& num : nums) res += to_string(num);
        return res;
    }
};