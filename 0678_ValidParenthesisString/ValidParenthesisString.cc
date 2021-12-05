class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        unordered_map<int, unordered_set<int>> record;
        
        return helper(s, 0, 0, record);
    }
private:
    bool helper(string& s, int index, int count, unordered_map<int, unordered_set<int>>& record) {
        if (index == s.size()) return !count;
        if (record[index].find(count) != record[index].end()) return false;
        
        if (s[index] == '(') {
            if (helper(s, index+1, count+1, record)) return true;
        }
        else if (s[index] == ')') {
            if (count <= 0) return false;
            if (helper(s, index+1, count-1, record)) return true;
        } else {
            if (helper(s, index+1, count+1, record) || helper(s, index+1, count, record) || count > 0 && helper(s, index+1, count-1, record)) return true;
        }
        
        record[index].insert(count);
        return false;
    }
};