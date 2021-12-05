class Solution {
public:
    int minOperations(int n) {
        int a = n/2;
        return a*n-a*a;
    }
};