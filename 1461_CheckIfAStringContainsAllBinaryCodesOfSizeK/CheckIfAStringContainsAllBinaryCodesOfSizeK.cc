class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> nums;
        int size = s.size()-k+1;
        for (int i=0;i<size;++i) {
            addNum(s.substr(i,k), nums);
        }
        return nums.size() == pow(2, k);
    }
private:
    void addNum(string s, unordered_set<int>& nums) {
        int res = 0;
        for (char& c : s) {
            res = (res<<1)|(c-'0');
        }
        nums.insert(res);
    }
};

// Rolling Hash:

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        size_t limit = pow(2, k);
        if (s.size()-k+1 < limit) return false;
        
        const int mask = limit-1;
        const int size = s.size();
        int num = 0;
        unordered_set<int> record;
        for (int i=0;i<k-1 && i<size;++i) {
            num = (num<<1)|(s[i]=='1');
        }
        for (int i=k-1;i<size;++i) {
            num = (num<<1)&mask|(s[i]=='1');
            record.insert(num);
        }
        return record.size() == limit;
    }
};