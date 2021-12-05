class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<bool> table(limit, false);
        int size = 0;
        for (int& num : nums) {
            table[num] = true;
            size = max(size, num);
        }
        table.resize(size+1);
        
        int res = 0;
        for (int i=1;i<=size;++i) {
            int found_val = 0;
            for (int cur = i;cur<=size;cur+=i) {
                if (table[cur]) {
                    found_val = found_val ? gcd(found_val, cur) : cur;
                    if (found_val == i) {
                        table[i] = true;
                        break;
                    }
                }
            }
            if (table[i]) ++res;
        }
        return res;
    }
private:
    const int limit = 2e5+1;
};