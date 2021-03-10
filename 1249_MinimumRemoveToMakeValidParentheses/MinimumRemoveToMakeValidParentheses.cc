class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        int index = s.size();
        for (int i=s.size()-1;i>=0;--i) {
            if (s[i] == '(') {
                if (!count) continue;
                --count;
            } else if (s[i] == ')') {
                ++count;
            }
            s[--index] = s[i];
        }
        int pre = 0;
        count = 0;
        while (index < s.size()) {
            if (s[index] == ')') {
                if (!count) {
                    ++index;
                    continue;
                }
                --count;
            } else if (s[index] == '(') {
                ++count;
            }
            s[pre++] = s[index++];
        }
        s.resize(pre);
        return s;
    }
};