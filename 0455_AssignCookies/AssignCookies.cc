class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size()-1;
        for (int i=g.size()-1;i>=0 && index >=0;--i) {
            if (g[i] <= s[index]) {
                --index;
            }
        }
        return s.size()-1-index;
    }
};