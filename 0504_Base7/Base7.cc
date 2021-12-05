class Solution {
public:
    string convertToBase7(int num) {
        if (!num) return "0";
        string res = "";
        int mark = 1;
        if (num < 0) {
            mark = -1;
            num = -num;
        }
        while (num) {
            res.push_back((num%7)+'0');
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return mark > 0 ? res : "-"+res;
    }
};