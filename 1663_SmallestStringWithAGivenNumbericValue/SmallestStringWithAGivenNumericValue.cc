class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        int index = n-1;
        while (k) {
            if (k>25) {
                res[index--] = 'z';
                k -= 25;
            } else {
                res[index] += k;
                break;
            }
        }
        return res;
    }
};