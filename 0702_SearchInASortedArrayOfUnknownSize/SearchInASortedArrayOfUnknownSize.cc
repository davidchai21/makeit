/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 1e4;
        while (left < right) {
            int mid = (left+right)/2;
            int val = reader.get(mid);
            if (val == target) return mid;
            else if (val < target) left = mid+1;
            else right = mid-1;
        }
        return reader.get(left) == target ? left : -1;
    }
};