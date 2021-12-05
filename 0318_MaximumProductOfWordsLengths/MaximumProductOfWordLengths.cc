class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);
        int res = 0;
        for (int i=0;i<n;++i) {
            mask[i] = helper(words[i]);
        
            for (int j=0;j<i;++j) {
                if (mask[i] & mask[j]) continue;
                res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
private:
    int helper(string& word) {
        int res = 0;
        for (char& c : word) {
            res |= 1<<(c-'a');
        }
        return res;
    }
};