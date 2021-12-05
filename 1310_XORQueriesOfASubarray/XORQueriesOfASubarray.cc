class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        for (int i=1;i<arr.size();++i) {
            arr[i] ^= arr[i-1];
        }
        for (int i=0;i<queries.size();++i) {
            res[i] = queries[i].front() ? arr[queries[i].back()]^arr[queries[i].front()-1] : arr[queries[i].back()];
        }
        return res;
    }
};