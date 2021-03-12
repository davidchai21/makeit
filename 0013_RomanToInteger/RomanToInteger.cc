class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        
        int index = s.size()-1;
        int res = 0;
        while (index >= 0) {
            if (index < s.size()-1 && m[s[index]] < m[s[index+1]]) res -= m[s[index]];
            else res += m[s[index]];
            --index;
        }
        return res;
    }
};