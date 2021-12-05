class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        int zero = 0;
        for (int & num : arr) {
            if (num < 0) {
                if (m.find(2*num) != m.end()) {
                    if (--m[2*num] == 0) m.erase(2*num);
                } else {
                    ++m[num];
                }
            } else if (!num) ++zero;
            else {
                if (num%2 == 0 && m.find(num/2) != m.end()) {
                    if (--m[num/2] == 0) m.erase(num/2);
                } else {
                    ++m[num];
                }
            }
        }
        return m.empty();
    }
};

// Another:

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int& num : arr) ++m[num];
        vector<int> keys(m.size());
        int index = 0;
        for (auto it = m.begin(); it != m.end(); ++it, ++index) {
            keys[index] = it->first;
        }
        sort(keys.begin(), keys.end(), [](int& a, int& b){
            return abs(a) < abs(b);
        });
        for (int & key : keys) {
            if (m[key*2] < m[key]) return false;
            m[key*2] -= m[key];
        }
        return true;
    }
};