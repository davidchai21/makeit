class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> p(n);
        for (int i=0;i<n;++i) p[i] = i;
        for (vector<int>& step : allowedSwaps) {
            _union(p, step[0], step[1]);
        }
        
        unordered_map<int, unordered_map<int, int>> m;
        for (int i=0;i<n;++i) {
            ++m[_find(p, i)][source[i]];
        }
        int res = 0;
        for (int i=0;i<n;++i) {
            int root = _find(p,i);
            if (m[root].find(target[i]) != m[root].end()) --m[root][target[i]];
        }
        for (auto it = m.begin();it!=m.end();++it) {
            for (auto _it = it->second.begin(); _it != it->second.end(); ++_it) {
                if (_it->second > 0) res += _it->second;
            }
        }
        return res;
    }
private:
    void _union(vector<int>& parent, int a, int b) {
        int pa = _find(parent, a);
        int pb = _find(parent, b);
        if (pa != pb) parent[pa] = pb;
    }
    
    int _find(vector<int>& parent, int a) {
        while (parent[a] != parent[parent[a]]) {
            parent[a] = parent[parent[a]];
        }
        return parent[a];
    }
};