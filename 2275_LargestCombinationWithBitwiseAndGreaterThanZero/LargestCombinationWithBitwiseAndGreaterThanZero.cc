class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32, 0);
        for(int& c : candidates) {
            add(c, count);
        }
        
        int res = 0;
        for(int& c : count) {
            res = max(res, c);
        }
        return res;
    }
private:
    void add(int val, vector<int>& count) {
        int i = 0;
        while (val) {
            if (val&1) ++count[i];
            ++i;
            val >>= 1;
        }
    }
};