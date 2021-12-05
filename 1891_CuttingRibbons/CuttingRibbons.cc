class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 1, right = 1e5;
        while (left < right) {
            int mid = (left+right+1)/2;
            if (helper(ribbons, mid, k)) left = mid;
            else right = mid-1;
        }
        return helper(ribbons, left, k) ? left : 0;
    }
private:
    bool helper(vector<int>& ribbons, int len, int k) {
        int count = 0;
        for (int & r : ribbons) {
            count += r/len;
        }
        return k <= count;
    }
};