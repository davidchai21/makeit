class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> record(n);
        for (int i=0;i<n;++i) record[i] = i;
        for (vector<int>& edge:edges) {
            if (!Union(record, edge[0]-1, edge[1]-1)) return edge;
        }
        return {};
    }
private:
    int find(vector<int>& record, int& k) {
        while (record[k] != record[record[k]]) {
            record[k] = record[record[k]];
        }
        return record[k];
    }
    
    bool Union(vector<int>& record, int a, int b) {
        int pa = find(record, a);
        int pb = find(record, b);
        if (pa == pb) return false;
        
        record[pa] = pb;
        return true;
    }
};