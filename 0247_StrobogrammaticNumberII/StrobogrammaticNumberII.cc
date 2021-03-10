class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        string s(n, '7');
        vector<string> res;
        helper(n, 0, s, res, m);
        return res;
    }
private:
    vector<char> start = {'1','6','8','9'};
    vector<char> mid = {'1','8','0'};
    vector<char> other = {'0','1','6','8','9'};
    
    void helper(const int& n, int index, string& s, vector<string>& res, unordered_map<char, char>& m) {
        if (index >= n || s[index] != '7') {
            res.push_back(s);
            return;
        }
        
        if (index == n-1-index) {
            for (int i=0;i<mid.size();++i) {
                s[index] = mid[i];
                helper(n, index+1, s, res, m);
                s[index] = '7';
            }
        } else if (index == 0) {
            for (int i=0;i<start.size();++i) {
                s[index] = start[i];
                s[n-1-index] = m[start[i]];
                helper(n, index+1, s, res, m);
                s[index] = s[n-1-index] = '7';
            }
        } else {
            for (int i=0;i<other.size();++i) {
                s[index] = other[i];
                s[n-1-index] = m[other[i]];
                helper(n, index+1, s, res, m);
                s[index] = s[n-1-index] = '7';
            }
        }
    }
};