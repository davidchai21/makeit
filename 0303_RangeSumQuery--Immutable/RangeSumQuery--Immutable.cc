class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size(), 0);
        sum[0] = nums.front();
        for (int i=1;i<nums.size();++i) {
            sum[i] = sum[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (!left) return sum[right];
        return sum[right]-sum[left-1];
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */