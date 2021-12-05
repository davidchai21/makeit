class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> record(m+1, vector<int>(n+1, 0));
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                record[i+1][j+1] = max(record[i+1][j+1], max((word1[i]==word2[j])+record[i][j], max(record[i][j+1], record[i+1][j])));
            }
        }
        return word1.size()+word2.size()-2*record.back().back();
    }
};

// O(n) space: 

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> record(n+1, 0);
        for (int i=0;i<m;++i) {
            vector<int> t(n+1, 0);
            for (int j=1;j<=n;++j) {
                t[j] = max(max(record[j], t[j-1]), (word1[i]==word2[j-1])+record[j-1]);
            }
            record.swap(t);
        }
        return m+n-2*record.back();
    }
};