class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        int left = 0, right = n1;
        const int k = (n1+n2+1)>>1;
        while (left < right) {
            int m1 = left + (right-left)/2;
            int m2 = k-m1;
            if (nums1[m1] < nums2[m2-1]) left = m1+1;
            else right = m1;
        }
        
        const int m1 = left;
        const int m2 = k-left;
        left = max(m1 <= 0 ? INT_MIN : nums1[m1-1],
                   m2 <= 0 ? INT_MIN : nums2[m2-1]);
        if ((n1+n2)&1) return left;
        
        right = min(m1 >= n1 ? INT_MAX : nums1[m1],
                    m2 >= n2 ? INT_MAX : nums2[m2]);
        return (left+right)/2.0;
    }
};