class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, int> mp;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n-1;++j) {
                if (grid[i][j]) {
                    for (int k=j+1;k<n;++k) {
                        if (grid[i][k]) ++mp[getKey(j, k)];
                    }
                }
            }
        }
        
        int res = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            res += it->second*(it->second-1)/2;
        }
        return res;
    }
private:
    inline int getKey(int a, int b) {
        return (a<<8)+b;
    }
};

// bitset:

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m==1 || n==1) return 0;
        
        vector<bitset<200>> s(m, bitset<200>());
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) s[i].set(j);
            }
        }
        
        int res = 0;
        for (int i=0;i<m-1;++i) {
            for (int j=i+1;j<m;++j) {
                auto ans = s[i] & s[j];
                int k = ans.count();
                res += k*(k-1)/2;
            }
        }
        return res;
    }
};