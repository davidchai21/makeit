class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int dis = 0;
        int d = INT_MIN;
        for (vector<int>& nut : nuts) {
            dis += helper(nut, tree)*2;
            d = max(d, helper(nut, tree) - helper(nut, squirrel));
        }
        return dis - d;
    }
private:
    int helper(vector<int>& nut, vector<int>& target) {
        return abs(nut[0]-target[0]) + abs(nut[1]-target[1]);
    }
};