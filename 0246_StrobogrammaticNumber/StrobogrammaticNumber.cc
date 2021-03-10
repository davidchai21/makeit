class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        for (int i=0;i<=n/2;++i) {
            if (table[num[i]-'0'] != num[n-1-i]) return false;
        }
        return true;
    }
private:
    vector<char> table = {'0', '1',' ',' ',' ',' ','9',' ','8','6'};
};