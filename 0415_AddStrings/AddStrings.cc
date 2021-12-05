class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return num1 == "0" ? num2 : num1;
        int i = num1.size()-1, j = num2.size()-1;
        int digit = 0;
        string res(max(num1.size(), num2.size())+1, '0');
        int index = res.size()-1;
        while (i>=0 || j>=0) {
            if (i>=0) {
                digit += num1[i--]-'0';
            }
            if (j>=0) {
                digit += num2[j--]-'0';
            }
            cout<<digit<<endl;
            res[index--] += digit%10;
            digit /= 10;
        }
        if (digit) res[index] = '1';
        index = 0;
        while (index < res.size() && res[index] == '0') ++index;
        return res.substr(index);
    }
};