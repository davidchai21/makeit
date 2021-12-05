class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = helper(0, 0, target);
        for (vector<int>& ghost : ghosts) {
            if (helper(ghost[0], ghost[1], target) <= dis) return false;
        }
        return true;
    }
private:
    int helper(int x, int y, const vector<int>& target) {
        return abs(x-target[0]) + abs(y-target[1]);
    }
};