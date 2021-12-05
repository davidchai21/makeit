class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int right = 0, left = 0;
        for (int& w : weights) {
            right += w;
            left = max(w, left);
        }
        if (D == 1) return right;
        
        while (left < right) {
            int mid = left + (right-left)/2;
            int n = helper(weights, mid);
            if (n <= D) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    int helper(vector<int>& weights, const int limit) {
        int count = 1;
        int load = 0;
        for (int& w : weights) {
            if (load + w > limit) {
                load = w;
                ++count;
            } else {
                load += w;
            }
        }
        return count;
    }
};