class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return helper(arr, visited, start);
    }
private:
    bool helper(vector<int>& arr, vector<bool>& visited, int index) {
        if (index < 0 || index >= arr.size() || visited[index]) return false;
        if (arr[index] == 0) return true;
        visited[index] = true;
        int left = index - arr[index];
        int right = index + arr[index];
        return helper(arr, visited, left) || helper(arr, visited, right);
    }
};