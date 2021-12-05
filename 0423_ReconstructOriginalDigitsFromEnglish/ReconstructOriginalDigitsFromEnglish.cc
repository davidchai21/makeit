class Solution {
public:
    string originalDigits(string s) {
        vector<int> record(26, 0);
        for (char& c : s) ++record[c-'a'];
        vector<int> count(10, 0);
        count[0] = record[25];
        count[8] = record[6];
        count[3] = record[7]-count[8];
        count[4] = record['r'-'a']-count[0]-count[3];
        count[5] = record[5]-count[4];
        count[7] = record['v'-'a']-count[5];
        count[6] = record['x'-'a'];
        count[2] = record['w'-'a'];
        count[9] = record['i'-'a']-count[6]-count[5]-count[8];
        count[1] = record['o'-'a']-count[0]-count[2]-count[4];
        
        string res = "";
        for (int i=0;i<10;++i) {
            while (count[i]-- > 0) {
                res += to_string(i);
            }
        }
        return res;
    }
};