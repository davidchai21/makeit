class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int l = ceil(sqrt(stoll(left)));
        int r = sqrt(stoll(right));
        int res = 0;
        helper("", l, r, res);
        return res;
    }
private:
    vector<string> mid = {"", "0", "1", "2", "3"};
    
    void helper(string num, int l, int r, int& res) {
        for (string& m : mid) {
            string t = getStr(num, m);
            if (t.empty() || t.front() == '0') continue;
            long long number = stoll(t);
            if (number > r) return;
            if (number >= l && number <= r && isPalindrome(to_string(number*number))) ++res;
            if (m.empty()) continue;
            helper(num+m, l, r, res);
        }
    }
    
    string getStr(string num, string mid) {
        string tail = num;
        reverse(tail.begin(), tail.end());
        return num+mid+tail;
    }
    
    bool isPalindrome(string s) {
        for (int left = 0, right = s.size()-1; left < right; ++left, --right) {
            if (s[left] != s[right]) return false;
        }
        return true;
    }
};