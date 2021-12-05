class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num : nums) {
            ++m[num-rev(num)];
        }
        
        long res = 0L;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res += (long)it->second*(it->second-1)/2;
        }
        return res%mod;
    }
private:
    const int mod = 1e9+7;
    
    inline int rev(int n) {
        int res = 0;
        while (n) {
            res = res*10+(n%10);
            n /= 10;
        }
        return res;
    }
};

// don't have to use long

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for (int& num : nums) {
            res = (res + m[num-rev(num)]++)%mod;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
    
    inline int rev(int n) {
        int res = 0;
        while (n) {
            res = res*10+(n%10);
            n /= 10;
        }
        return res;
    }
};