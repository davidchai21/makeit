// O(m+n):

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0], n = dim[1];
        int right = n-1;
        for (int i=0;i<m;++i) {
            while (right >=0 && binaryMatrix.get(i, right)) --right;
            if (right == -1) return 0;
        }
        return right == n-1 ? -1 : (right+1);
    }
};

// Binary Search:

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0], n = dim[1];
        int res = n;
        for (int i = 0;i<m;++i) {
            res = min(res, helper(binaryMatrix, i, n));
        }
        return res == n ? -1 : res;
    }
private:
    int helper(BinaryMatrix& binaryMatrix, int& row, int& n) {
        if (binaryMatrix.get(row, n-1) == 0) return n;
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (binaryMatrix.get(row, mid)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};