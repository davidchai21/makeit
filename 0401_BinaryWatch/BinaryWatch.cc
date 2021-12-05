class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<bool> hour(4, false), min(6, false);
        for (int i=0;i<=num;++i) {
            if (i>4 || num-i>6) continue;
            vector<string> h, m;
            getHour(i, hour, 0, h);
            getMin(num-i, min, 0, m);
            for (string& _h : h) {
                for (string& _m : m) {
                    res.push_back(_h+":"+_m);
                }
            }
        }
        return res;
    }
private:
    vector<int> hour = {8, 4, 2, 1};
    vector<int> min = {32, 16, 8, 4, 2, 1};
    
    int h_helper(vector<bool>& v) {
        int res = 0;
        for (int i=0;i<4;++i) {
            res += v[i]*hour[i];
        }
        return res;
    }
    
    int m_helper(vector<bool>& v) {
        int res = 0;
        for (int i=0;i<6;++i) {
            res += v[i]*min[i];
        }
        return res;
    }
    
    void getHour(const int n, vector<bool>& v, int index, vector<string>& res) {
        if (index == v.size()) {
            if (count(v.begin(), v.end(), true) == n) {
                int h = h_helper(v);
                if (h < 12) res.push_back(to_string(h));
            }
            return;
        }
        
        getHour(n, v, index+1, res);
        v[index] = true;
        getHour(n, v, index+1, res);
        v[index] = false;
    }
    
    void getMin(const int n, vector<bool>& v, int index, vector<string>& res) {
        if (index == v.size()) {
            if (count(v.begin(), v.end(), true) == n) {
                int m = m_helper(v);
                if (m < 60) {
                    string t = to_string(m);
                    res.push_back(t.size() == 1 ? "0"+t : t);
                }
            }
            return;
        }
        
        getMin(n, v, index+1, res);
        v[index] = true;
        getMin(n, v, index+1, res);
        v[index] = false;
    }
};