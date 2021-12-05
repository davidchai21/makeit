class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> s;
        s.push_back(bitset<26>());
        int res = 0;
        for (string& str : arr) {
            bitset<26> num;
            for (char& c : str) num.set(c-'a');
            if (num.count() < str.size()) continue;
            res = max(res, (int)str.size());
            
            int size = s.size();
            for (int i=0;i<size;++i) {
                if ((s[i] & num).any()) continue;
                auto p = s[i] | num;
                s.push_back(p);
                res = max<int>(res, s[i].count() + num.count());
            }
        }
        return res;
    }
};