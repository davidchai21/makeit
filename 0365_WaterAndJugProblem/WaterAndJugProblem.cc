class Solution {
public:
    bool canMeasureWater(int j1, int j2, int target) {
        int k = gcd(j1, j2);
        if (target%k) return false;
        return j1+j2>=target;
    }
};