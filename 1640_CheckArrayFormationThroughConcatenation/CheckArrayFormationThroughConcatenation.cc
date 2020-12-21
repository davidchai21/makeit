class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> m;
        for (vector<int> p:pieces) m[p.front()] = p;
        int j = 0;
        for (int i=0;i<arr.size();) {
            if (m.find(arr[i]) == m.end()) return false;
            int index = arr[i];
            for (j=0;j<m[index].size();++j) {
                if (arr[i] != m[index][j]) return false;
                if (++i >= arr.size() && j != m[index].size()-1) return false;
            }
        }
        return true;
    }
};