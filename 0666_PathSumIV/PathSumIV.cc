class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int,int> m;
        build(nums, m);
        int res = 0;
        for (auto it = m.begin(); it!=m.end();++it) {
            int left = (it->first/10+1)*10 + 2*(it->first%10) - 1;
            int right = (it->first/10+1)*10 + 2*(it->first%10);
            if (m.find(left) == m.end() && m.find(right) == m.end()) res += it->second;
        }
        return res;
    }
private:
    void build(vector<int>& nums, unordered_map<int,int>& m) {
        for (int& num:nums) {
            int key = num/10;
            int val = num%10 + m[(key/10-1)*10+(key%10+1)/2];
            m[key] = val;
        }
    }
};