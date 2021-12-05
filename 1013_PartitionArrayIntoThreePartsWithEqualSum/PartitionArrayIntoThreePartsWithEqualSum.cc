class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        int sum = 0;
        for (int i=0;i<arr.size();++i) {
            sum += arr[i];
            m[sum].push_back(i);
        }
        if (sum%3) return false;
        if (!sum) return m[0].size() >= 3;
        return m.find(sum/3) != m.end() && m.find(sum/3*2) != m.end() && m[sum/3].front() < m[sum/3*2].back();
    }
};

// O(1) space:

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0, zero = 0;
        for (int & a : arr) {
            sum += a;
            if (!sum) ++zero;
        }
        if (sum%3) return false;
        if (!sum) return zero >= 3;
        
        int left = -1, right = -1;
        int s = 0;
        for (int i = 0; i<arr.size();++i) {
            s += arr[i];
            if (s == sum/3 && left == -1) left = i;
            if (s == sum/3*2) right = i;
        }
        return left != -1 && right != -1 && left < right;
    }
};