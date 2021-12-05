class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, int> count;
        for (vector<int>& _mat : mat) {
            for (int& num : _mat) ++count[num];
        }
        
        int res = -1;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second == m) {
                res = res==-1 ? it->first : min(res, it->first);
            }
        }
        return res;
    }
};

// Binary Search:

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int& val : mat[0]) {
            bool found = true;
            for (int i=1;i<m;++i) {
                if (binary_search(mat[i].begin(), mat[i].end(), val)) continue;
                found = false;
                break;
            }
            if (found) {
                return val;
            }
        }
        return -1;
    }
};