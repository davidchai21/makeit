class Solution {
public:
    int twoEggDrop(int n) {
        int k = sqrt(2*n+0.25)-0.5;
        return k*(k+1)/2 == n ? k : k+1;
    }
};