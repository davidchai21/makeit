class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> m;
        for (vector<string>& region : regions) {
            for (int i=1;i<region.size();++i) {
                m[region[i]] = region.front();
            }
        }
        vector<string> path1, path2;
        findPath(path1, region1, m);
        findPath(path2, region2, m);
        string res = "";
        for (int i=path1.size()-1, j=path2.size()-1; i>=0 && j>=0;--i, --j) {
            if (path1[i] == path2[j]) res = path1[i];
            else break;
        }
        return res;
    }
private:
    void findPath(vector<string>& path, string start, unordered_map<string, string>& m) {
        while (m.find(start) != m.end()) {
            path.push_back(start);
            start = m[start];
        }
        path.push_back(start);
    }
};