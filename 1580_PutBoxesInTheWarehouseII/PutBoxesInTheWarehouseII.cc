class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int res = 0;
        sort(boxes.begin(), boxes.end(), greater<int>());
        int left = 0, right = warehouse.size()-1, n = boxes.size();
        int leftHeight = warehouse[left], rightHeight = warehouse[right];
        for (int i=0;i<n && left<=right;++i) {
            if (boxes[i] <= leftHeight) {
                if (++left < warehouse.size()) leftHeight = min(leftHeight, warehouse[left]);
                ++res;
            } else if (boxes[i] <= rightHeight) {
                if (--right) rightHeight = min(rightHeight, warehouse[right]);
                ++res;
            }
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), greater<int>());
        int left = 0, right = warehouse.size()-1;
        int res = 0;
        for (int i=0;i<boxes.size() && left <= right; ++i) {
            if (boxes[i] <= warehouse[left]) {
                ++res;
                ++left;
            } else if (boxes[i] <= warehouse[right]) {
                ++res;
                --right;
            }
        }
        return res;
    }
};