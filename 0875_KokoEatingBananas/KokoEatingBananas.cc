class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = (left+right)/2;
            if (helper(piles, h, mid)) right = mid;
            else left = mid+1;
        }
        return right;
    }
private:
    inline bool helper(vector<int>& ps, int h, int s) {
        int res = 0;
        for (int & p : ps) {
            res += (p-1)/s+1;
        }
        return res <= h;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left+right)/2;
            if (helper(piles, h, mid)) right = mid;
            else left = mid+1;
        }
        return right;
    }
private:
    inline bool helper(vector<int>& ps, int h, int s) {
        int res = 0;
        for (int & p : ps) {
            res += (p-1)/s+1;
        }
        return res <= h;
    }
};