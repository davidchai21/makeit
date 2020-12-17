class Solution {
public:
    Solution(vector<int>& nums) {
        base = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return base;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = base.size();
        vector<int> cur(base);
        for (int i=0;i<n-1;++i) {
            int index = rand()%(n-i);
            swap(cur[i], cur[index+i]);
        }
        return cur;
    }
private:
    vector<int> base;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */