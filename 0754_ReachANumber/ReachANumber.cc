class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) return reachNumber(-target);
        int least = ceil(sqrt(2.0*target+0.25)-0.5);
        while ((least*(least+1)-2*target)%4) ++least;
        return least;
    }
};