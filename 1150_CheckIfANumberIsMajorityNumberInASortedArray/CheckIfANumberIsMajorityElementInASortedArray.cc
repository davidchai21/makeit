class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        for (int n:nums) {
            if (n == target) ++count;
            else --count;
        }
        return count>0;
    }
};

// Binary Search:

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int N=nums.size();
        int left=0,right=N,mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>=target){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        if(left<N/2&&nums[left+N/2]==target || N%2 && left == N/2 && nums.back() == target){
            return true;
        }else{
            return false;
        }
    }
};