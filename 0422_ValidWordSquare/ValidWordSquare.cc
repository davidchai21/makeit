class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        int n = words[0].size();
        if (m != n) return false;
        
        for (int i=0;i<n;++i) {
            if (words[i].size() > n) return false;
            for (int j=i;j<n;++j) {
                if (j >= words[i].size() && i >= words[j].size()) continue;
                if (j >= words[i].size() || i >= words[j].size() || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};