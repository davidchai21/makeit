/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int res = -1;
        int i=0;
        for (;i<n;) {
            int j=1;
            while (j<n) {
                if (knows(i,(i+j)%n)) break;
                ++j;
            }
            if (j==n && helper(i,n)) {
                res = i;
                break;
            }
            i += j;
        }
        return res;
    }
private:
    bool helper(int i, int n) {
        for (int k=0;k<n;++k) {
            if (!knows(k,i)) return false;
        }
        return true;
    }
};