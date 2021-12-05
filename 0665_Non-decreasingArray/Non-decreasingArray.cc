class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return true;
        
        int pre = INT_MIN;
        int index = 0;
        while (index < n-1) {
            if (nums[index] > nums[index+1]) break;
            pre = nums[index++];
        }
        if (index == n-1) return true;
        
        int t = nums[index];
        nums[index] = pre;
        int i=index;
        for (;i<n-1;++i) {
            if (nums[i]>nums[i+1]) break;
        }
        if (i==n-1) return true;
        
        nums[index] = t;
        nums[index+1] = t;
        for (i=index+1;i<n-1;++i) {
            if (nums[i] > nums[i+1]) break;
        }
        return i==n-1;
    }
};

// Another:

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        for (int i=1;i<n;++i) {
            if (nums[i] < nums[i-1]) {
                if (flag) return false;
                flag = true;
                
                if (i<2 || nums[i]>=nums[i-2]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return true;
    }
};