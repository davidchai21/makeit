class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        int index = 0;
        for (const vector<int>& query : queries) {
            int count = 0;
            for (const vector<int>& point : points) {
                count += helper(point, query);
            }
            res[index++] = count;
        }
        return res;
    }
private:
    inline bool helper(const vector<int>& point, const vector<int>& query) {
        int x = point.front()-query.front();
        int y = point.back()-query[1];
        return x*x+y*y <= query.back()*query.back();
    }
};