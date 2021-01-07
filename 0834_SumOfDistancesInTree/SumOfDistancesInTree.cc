class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> res(N,0);
        vector<int> count(N,0);
        vector<vector<int>> record(N);
        for (vector<int>& edge : edges) {
            record[edge[0]].push_back(edge[1]);
            record[edge[1]].push_back(edge[0]);
        }
        
        postHelper(count, res, record, 0, -1);
        preHelper(count, res, record, 0, -1, N);
        return res;
    }
private:
    void postHelper(vector<int>& count, vector<int>& res, vector<vector<int>>& record, int root, int parent) {
        for (int& i : record[root]) {
            if (i != parent) {
                postHelper(count, res, record, i, root);
                count[root] += count[i];
                res[root] += res[i] + count[i];
            }
        }
        ++count[root];
    }
    
    void preHelper(vector<int>& count, vector<int>& res, vector<vector<int>>& record, int root, int parent, int N) {
        for (int& i : record[root]) {
            if (i != parent) {
                res[i] = res[root]-count[i] + N-count[i];
                preHelper(count, res, record, i, root, N);
            }
        }
    }
};