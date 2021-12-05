class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num : nums) ++m[num];
        vector<vector<int>> res(1, vector<int>());

        for (auto it = m.begin(); it != m.end(); ++it) {
            vector<vector<int>> cur;
            for (int k=0;k<=it->second;++k) {
                cur.push_back(vector<int>(k, it->first));
            }
            vector<vector<int>> node;
            for (int i=0;i<res.size();++i) {
                for (int j=0;j<cur.size();++j) {
                    node.push_back(res[i]);
                    for (int k=0;k<cur[j].size();++k) {
                        node.back().push_back(cur[j][k]);
                    }
                }
            }
            res.swap(node);
        }
        return res;
    }
};