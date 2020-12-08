// DP:

class Solution {
public:
    int numTrees(int n) {
        vector<int> table(n+1,1);
        for (int i=2;i<=n;++i) {
            int sum = 0;
            for (int j=0;j<i;++j) {
                sum += table[j]*table[i-1-j];
            }
            table[i]=sum;
        }
        return table[n];
    }
};