class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i=0;i<n;++i) {
            if (nums[i]%n==0) continue;
            int slow = i, fast = i;
            int mark = nums[i] > 0 ? 1 : -1;
            while (mark*nums[getNext(fast, nums, n)] > 0 && mark*nums[getNext(getNext(fast, nums, n), nums, n)] > 0) {
                slow = getNext(slow, nums, n);
                fast = getNext(getNext(fast, nums, n), nums, n);
                if (slow == fast) {
                    if (slow == getNext(slow, nums, n)) break;
                    return true;
                }
            }
        }
        return false;
    }
private:
    int getNext(int index, vector<int>& nums, const int& n) {
        return ((index+nums[index])%n+n)%n;
    }
};

// Better:

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i=0;i<n;++i) {
            if (nums[i]%n==0) continue;
            int slow = i, fast = i;
            int mark = nums[i] > 0 ? 1 : -1;
            while (mark*nums[getNext(fast, nums, n)] > 0 && mark*nums[getNext(getNext(fast, nums, n), nums, n)] > 0) {
                slow = getNext(slow, nums, n);
                fast = getNext(getNext(fast, nums, n), nums, n);
                if (slow == fast) {
                    if (slow == getNext(slow, nums, n)) break;
                    return true;
                }
            }
            slow = i;
            while (mark*nums[slow] > 0) {
                int index = getNext(slow, nums, n);
                nums[slow] = 0;
                slow = index;
            }
        }
        return false;
    }
private:
    int getNext(int index, vector<int>& nums, const int& n) {
        return ((index+nums[index])%n+n)%n;
    }
};