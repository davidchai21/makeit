class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int left = 0, right = nums.size()-1; left < right; ++left, --right) {
            res += nums[right] - nums[left];
        }
        return res;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size()/2];
        int res = 0;
        for (int i=0;i<nums.size()/2;++i) {
            res += mid - nums[i];
        }
        for (int i=nums.size()/2;i<nums.size();++i) {
            res += nums[i]-mid;
        }
        return res;
    }
};

// Quick select:

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = quickSelect(nums, 0, nums.size()-1);
        int res = 0;
        for (int i=0;i<nums.size()/2;++i) {
            res += mid-nums[i];
        }
        for (int i=nums.size()/2;i<nums.size();++i) {
            res += nums[i] - mid;
        }
        return res;
    }
private:
    int quickSelect(vector<int>& nums, int left, int right) {
        if (left == right) return nums.front();
        
        int mid = 0;
        const int target = nums.size()/2;
        while ((mid = partition(nums, left, right)) != target) {
            if (mid > target) right = mid-1;
            else left = mid+1;
        }
        return nums[target];
    }
    
    int partition(vector<int>& nums, int left, int right) {
        if (left == right) return left;
        
        int index = rand()%(right+1-left) + left;
        swap(nums[index], nums[right]);
        int pivot = nums[right];
        for (int i=left;i<right;++i) {
            if (nums[i] <= pivot) {
                swap(nums[left++], nums[i]);
            }
        }
        swap(nums[left], nums[right]);
        return left;
    }
};