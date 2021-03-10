class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size()-1;
        while (index >= 0 && s[index] == ' ') --index;
        if (index < 0) return 0;
        int head = index;
        while (head >= 0 && s[head] != ' ') --head;
        return index-head;
    }
};