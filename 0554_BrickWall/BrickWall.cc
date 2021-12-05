class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        for (const vector<int>& w : wall) {
            int sum = w.front();
            for (int i=1;i<w.size();++i) {
                ++m[sum];
                sum += w[i];
            }
        }
        
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res = max(res, it->second);
        }
        return wall.size()-res;
    }
};

// Another:

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        int res = 0;
        for (const vector<int>& w : wall) {
            int sum = w.front();
            for (int i=1;i<w.size();++i) {
                res = max(res, ++m[sum]);
                sum += w[i];
            }
        }
        return wall.size()-res;
    }
};