class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited(n, false);
        int res = 0;
        helper(n, visited, 0, res);
        return res;
    }
private:
    void helper(int& n, vector<bool>& visited, int pos, int& res) {
        if (pos >= n) {
            ++res;
            return;
        }
        
        for (int i=0;i<n;++i) {
            if (!visited[i] && ((pos+1)%(i+1)==0 || (i+1)%(pos+1)==0)) {
                visited[i] = true;
                helper(n, visited, pos+1, res);
                visited[i] = false;
            }
        }
    }
};