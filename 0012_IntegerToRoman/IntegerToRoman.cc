// Better:

class Solution {
public:
    string intToRoman(int num) {
        int index = 0;
        string res = "";
        while (num) {
            if (num >= digit[index]) {
                res += dic[index];
                num -= digit[index];
            } else ++index;
        }
        return res;
    }
private:
    const array<int, 13> digit = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const array<string, 13> dic = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
};

// Original:

class Solution {
public:
    string intToRoman(int num) {
        return thousand[num/1000] + hundred[(num%1000)/100] + ten[(num%100)/10] + one[num%10];
    }
private:
    const vector<string> thousand = {"", "M", "MM","MMM"};
    const vector<string> hundred = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const vector<string> ten = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const vector<string> one = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
};