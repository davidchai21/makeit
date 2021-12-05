class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1, 0);
        vector<bool> seen(n+1, false);
        for (vector<int>& t : trust) {
            ++count[t.back()];
            seen[t.front()] = true;
        }
        
        int res = -1;
        for (int i=1;i<=n;++i) {
            if (count[i] == n-1 && !seen[i]) {
                if (res == -1) res = i;
                else return -1;
            }
        }
        return res;
    }
};

// One array:

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1, 0);
        for (vector<int>& t : trust) {
            ++count[t.back()];
            --count[t.front()];
        }
        
        for (int i=1;i<=n;++i) {
            if (count[i] == n-1) return i;
        }
        return -1;
    }
};