class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (6*m < 1*n || 6*n < 1*m) return -1;
        
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2) return 0;
        // to make sum1 > sum2
        if (sum1 < sum2) {
            nums1.swap(nums2);
            swap(sum1, sum2);
        }
        
        vector<int> record1(7,0), record2(7,0);
        for (int& num : nums1) ++record1[num];
        for (int& num : nums2) ++record2[num];
        
        int res = 0;
        int index1 = 6, index2 = 1;
        while (index1 && !record1[index1]) --index1;
        while (index2 < 7 && !record2[index2]) ++index2;
        while (sum1 > sum2) {
            if (index1 == 0) {
                sum2 += 6-index2;
                if (!--record2[index2]) ++index2;
            } else if (index2 == 7) {
                sum1 -= index1-1;
                if (!--record1[index1]) --index1;
            } else {
                if (6-index2 > index1-1) {
                    sum2 += 6-index2;
                    if (!--record2[index2]) ++index2;
                } else {
                    sum1 -= index1-1;
                    if (!--record1[index1]) --index1;
                }
            }
            ++res;
        }
        return res;
    }
};