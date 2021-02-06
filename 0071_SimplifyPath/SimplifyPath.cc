class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string filename = "";
        for (char& c : path) {
            if (c == '/') {
                if (filename.empty()) continue;
                if (filename == ".") {}
                else if (filename == "..") {
                    if (!st.empty()) st.pop();
                } else st.push(filename);
                filename = "";
            } else {
                filename.push_back(c);
            }
        }
        if (!filename.empty()) {
            if (filename == ".") {}
            else if (filename == "..") {
                if (!st.empty()) st.pop();
            }
            else st.push(filename);
        }
        
        string res = "";
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};

// vector as stack:

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string filename = "";
        for (char& c : path) {
            if (c == '/') {
                if (filename.empty() || filename == ".") {}
                else if (filename == "..") {
                    if (!st.empty())  st.pop_back();
                } else st.push_back(filename);
                filename = "";
            } else filename.push_back(c);
        }
        if (!filename.empty()) {
            if (filename == ".") {}
            else if (filename == "..") {
                if (!st.empty()) st.pop_back();
            } else st.push_back(filename);
        }
        
        string res = "";
        for (string& s : st) {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};