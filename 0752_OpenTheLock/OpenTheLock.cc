class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.find("0000") != dead.end() || dead.find(target) != dead.end()) return -1;
        if (target == "0000") return 0;
        unordered_set<string> fseen, bseen;
        queue<string> forward, backward;
        forward.push("0000");
        fseen.insert("0000");
        backward.push(target);
        bseen.insert(target);
        
        int res = 0;
        while (!forward.empty() && !backward.empty()) {
            int size = forward.size();
            ++res;
            while (size--) {
                string num = forward.front();
                forward.pop();
                for (int i=0;i<4;++i) {
                    string copy = num;
                    char up = (num[i]-'0'+1)%10+'0';
                    char down = (num[i]-'0'+9)%10+'0';
                    copy[i] = up;
                    if (dead.find(copy)==dead.end()) {
                        if (fseen.find(copy) == fseen.end()) {
                            forward.push(copy);
                            fseen.insert(copy);
                        }
                        if (bseen.find(copy) != bseen.end()) return res;
                    }
                    copy[i] = down;
                    if (dead.find(copy)==dead.end()) {
                        if (fseen.find(copy) == fseen.end()) {
                            forward.push(copy);
                            fseen.insert(copy);
                        }
                        if (bseen.find(copy) != bseen.end()) return res;
                    }
                }
            }
            
            ++res;
            size = backward.size();
            while (size--) {
                string num = backward.front();
                backward.pop();
                for (int i=0;i<4;++i) {
                    string copy = num;
                    char up = (num[i]-'0'+1)%10+'0';
                    char down = (num[i]-'0'+9)%10+'0';
                    copy[i] = up;
                    if (dead.find(copy)==dead.end()) {
                        if (bseen.find(copy) == bseen.end()) {
                            backward.push(copy);
                            bseen.insert(copy);
                        }
                        if (fseen.find(copy) != fseen.end()) return res;
                    }
                    copy[i] = down;
                    if (dead.find(copy)==dead.end()) {
                        if (bseen.find(copy) == bseen.end()) {
                            backward.push(copy);
                            bseen.insert(copy);
                        }
                        if (fseen.find(copy) != fseen.end()) return res;
                    }
                }
            }
        }
        return -1;
    }
};

// Single-queue:

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.find("0000") != dead.end()) return -1;
        if (target == "0000") return 0;
        queue<string> q;
        unordered_set<string> seen;
        q.push("0000");
        seen.insert("0000");
        int res = 0;
        while (!q.empty()) {
            ++res;
            int size = q.size();
            while (size--) {
                string num = q.front();
                q.pop();
                for (int i=0;i<4;++i) {
                    string copy = num;
                    char up = (num[i]-'0'+1)%10+'0';
                    char down = (num[i]-'0'+9)%10+'0';
                    copy[i] = up;
                    if (dead.find(copy) == dead.end()) {
                        if (target == copy) return res;
                        if (seen.find(copy) == seen.end()) {
                            seen.insert(copy);
                            q.push(copy);
                        }
                    }
                    copy[i] = down;
                    if (dead.find(copy) == dead.end()) {
                        if (target == copy) return res;
                        if (seen.find(copy) == seen.end()) {
                            seen.insert(copy);
                            q.push(copy);
                        }
                    }
                }
            }
        }
        return -1;
    }
};