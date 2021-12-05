class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end());
        int res = 0;
        for (int i=0;i<nums1.size(); ++i) {
            res += nums1[i] * nums2[i];
        }
        return res;
    }
};