class Solution {
public:
    string numberToWords(int num) {
        if (!num) return "Zero";
        string res = "";
        for (int i=0;i<4 && num;++i) {
            string cur = helper(num%1000);
            if (!cur.empty()) {
                res = cur + (i ? " " : "") + suffix[i] + (res.empty() ? "" : " ") + res;
            }
            num /= 1000;
        }
        return res;
    }
private:
    const vector<string> suffix = {"", "Thousand", "Million", "Billion"};
    const vector<string> single = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> tenth = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> TwoD = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string helper(int n) {
        string res = "";
        if (n/100) {
            res = single[n/100] + " Hundred";
        }
        n = n%100;
        if (n == 0) {
            return res;
        }
        if (n<10) {
            res += (res.empty() ? "" : " ") +single[n];
        } else if (n<20) {
            res += (res.empty() ? "" : " ")+tenth[n-10];
        } else {
            res += (res.empty() ? "" : " ")+TwoD[n/10];
            if (n%10) res += " "+single[n%10];
        }
        return res;
    }
};