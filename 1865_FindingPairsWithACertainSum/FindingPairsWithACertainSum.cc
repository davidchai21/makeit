class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        b = nums2;
        for (int & num : nums2) ++m[num];
        for (int & num : nums1) ++ma[num];
    }
    
    void add(int index, int val) {
        --m[b[index]];
        if (m[b[index]] == 0) m.erase(b[index]);
        b[index] += val;
        ++m[b[index]];
    }
    
    int count(int tot) {
        int res = 0;
        for (auto it = ma.begin(); it != ma.end(); ++it) {
            if (m.find(tot-it->first) != m.end()) {
                res += it->second*m[tot-it->first];
            }
        }
        return res;
    }
private:
    vector<int> b;
    unordered_map<int, int> m;
    unordered_map<int, int> ma;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */