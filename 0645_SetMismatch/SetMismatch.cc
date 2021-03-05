class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> record(nums.size()+1, 0);
        for (int& num : nums) ++record[num];
        vector<int> res(2,0);
        for (int i=1;i<record.size();++i) {
            if (record[i] == 0) res[1] = i;
            else if (record[i] == 2) res[0] = i;
        }
        return res;
    }
};

// O(1) space:

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2,0);
        for (int i=0;i<nums.size();++i) {
            if (nums[abs(nums[i])-1] < 0) {
                res[0] = abs(nums[i]);
            } else nums[abs(nums[i])-1] *= -1;
        }
        for (int i=0;i<nums.size();++i) {
            if (nums[i] > 0) res[1] = i+1;
        }
        return res;
    }
};

// Bit manipulation:

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i=0;i<n;++i) {
            sum ^= (i+1)^nums[i];
        }
        sum &= -sum;
        cout<<sum<<endl;
        
        int acc1 = 0, acc2 = 0;
        for (int i=0;i<n;++i) {
            if ((i+1)&sum) {
                acc1 ^= (i+1);
            } else {
                acc2 ^= (i+1);
            }
            if (nums[i]&sum) {
                acc1 ^= nums[i];
            } else {
                acc2 ^= nums[i];
            }
        }
        for (int& num : nums) {
            if (acc1 == num) return {acc1, acc2};
        }
        return {acc2, acc1};
    }
};