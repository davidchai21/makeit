class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> table(n, vector<int>(n));
        for (int i=0;i<n;++i) {
            for (int j=i;j>=0;--j) {
                if (i==j) table[i][j] = -piles[i];
                else {
                    int turn = (j+1-i)%2;
                    if (turn) {
                        table[j][i] = min(-piles[j]+table[j+1][i], -piles[i]+table[j][i-1]);
                    } else {
                        table[j][i] = max(piles[j]+table[j+1][i], piles[i]+table[j][i-1]);
                    }
                }
            }
        }
        return table[0][n-1]>0;
    }
};

// General Way:

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> table(n, vector<int>(n,0));
        for (int i=0;i<n;++i) {
            for (int j=i;j>=0;--j) {
                if (i==j) table[i][i] = piles[i];
                else {
                    table[j][i] = max(piles[j]-table[j+1][i], piles[i]-table[j][i-1]);
                }
            }
        }
        return table[0][n-1]>0;
    }
};

// Math way:

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};