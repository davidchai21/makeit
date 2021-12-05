class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int p1 = INT_MIN, p2 = p1, p3 = p1;
        int m1 = INT_MAX, m2 = m1, m3 = m1;
        for (int & num : nums) {
            if (num > p1) {
                p3 = p2, p2 = p1, p1 = num;
            } else if (num > p2) {
                p3 = p2, p2 = num;
            } else if (num > p3) {
                p3 = num;
            }
            
            if (num < m1) {
                m3 = m2, m2 = m1, m1 = num;
            } else if (num < m2) {
                m3 = m2, m2 = num;
            } else if (num < m3) {
                m3 = num;
            }
        }

        return max(p1*p2*p3, p1*m1*m2);
    }
};