class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string& email : emails) {
            size_t pos = email.find('@');
            s.insert(helper(email.substr(0, pos)) + "@" + email.substr(pos+1));
        }
        return s.size();
    }
private:
    inline string helper(string s) {
        string res;
        for (char& c : s) {
            if (c == '.') continue;
            else if (c == '+') break;
            res.push_back(c);
        }
        return res;
    }
};

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string& email : emails) {
            size_t pos = email.find('@');
            s.insert(helper(email.substr(0, pos)) + email.substr(pos));
        }
        return s.size();
    }
private:
    inline string helper(string s) {
        string res;
        for (char& c : s) {
            if (c == '.') continue;
            else if (c == '+') break;
            res.push_back(c);
        }
        return res;
    }
};