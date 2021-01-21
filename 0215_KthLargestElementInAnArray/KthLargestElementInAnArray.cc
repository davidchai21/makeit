class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

// Quick Select:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while (1) {
            int v = partition(nums, left, right);
            if (v == k-1) return nums[v];
            else if (v > k-1) right = v-1;
            else left = v+1;
        }
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int index = (rand() % (right-left+1)) + left;
        swap(nums[left], nums[index]);
        return helper(nums, left, right);
    }
    
    int helper(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1;
        int r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            } else {
                if (nums[l] >= pivot) ++l;
                if (nums[r] <= pivot) --r;
            }
        }
        swap(nums[r], nums[left]);
        return r;
    }
};