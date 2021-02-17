class Solution {
public:
    string decodeString(string s) {
        vector<char> st;
        for (char& c : s) {
            if (c == ']') {
                string str = "";
                while (st.back() != '[') {
                    str.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back();
                int base = 1;
                int k = 0;
                while (!st.empty() && isdigit(st.back())) {
                    k += base * (st.back()-'0');
                    st.pop_back();
                    base *= 10;
                }
                while (k--) {
                    for (int i=str.size()-1;i>=0;--i) {
                        st.push_back(str[i]);
                    }
                }
            } else st.push_back(c);
        }
        return string(st.begin(), st.end());
    }
};

// Double stack:

class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> alpha;
        int k = 0;
        string str = "";
        for (char& c : s) {
            if (isdigit(c)) k = k*10+c-'0';
            else if (isalpha(c)) str.push_back(c);
            else if (c == '[') {
                count.push(k);
                alpha.push(str);
                k = 0;
                str = "";
            } else {
                string base_s = alpha.top();
                alpha.pop();
                k = count.top();
                count.pop();
                while (k>0) {
                    base_s.append(str);
                    k--;
                }
                str = base_s;
            }
        }
        return str;
    }
};

// Recursive:

class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
private:
    string helper(string& s, int& index) {
        string res = "";
        while (index < s.size() && s[index] != ']') {
            if (!isdigit(s[index])) {
                res.push_back(s[index++]);
            } else {
                int k = 0;
                while (index < s.size() && isdigit(s[index])) {
                    k = k*10+s[index++]-'0';
                }
                
                ++index;
                string str = helper(s, index);
                ++index;
                
                while (k-- > 0) {
                    res.append(str);
                }
            }
        }
        return res;
    }
};