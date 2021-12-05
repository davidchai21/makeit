class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> record(26, 0);
        vector<string> res;
        if (!build(s, record)) return res;
        
        string str(s.size(), ' ');
        int size = s.size()/2;
        if (s.size()%2) {
            int i=0;
            for (;i<26;++i) {
                if (record[i]&1) break;
            }
            str[size] = 'a'+i;
        }
        helper(record, 0, size, str, res);
        return res;
    }
private:
    bool build(string & s, vector<int>& record) {
        int count = 0;
        for (char& c : s) {
            ++record[c-'a'];
        }
        for (int & num : record) {
            if (num&1) {
                if (count) return false;
                ++count;
            }
        }
        return true;
    }
    
    void helper(vector<int>& record, int index, int size, string& s, vector<string>& res) {
        if (index == size) {
            res.push_back(s);
            return;
        }
        
        for (int i=0;i<26;++i) {
            if (record[i] > 1) {
                record[i] -= 2;
                s[index] = s[s.size()-1-index] = i+'a';
                helper(record, index+1, size, s, res);
                record[i] += 2;
            }
        }
    }
};