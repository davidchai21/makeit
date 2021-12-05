class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) return num;
        string s = to_string(num);
        vector<int> parent(s.size());
        parent.back() = parent.size()-1;
        for (int i=parent.size()-2;i>=0;--i) {
            if (s[i] > s[parent[i+1]]) parent[i] = i;
            else parent[i] = parent[i+1];
        }
        
        int index = 0;
        while (index < s.size() && s[parent[index]] == s[index]) ++index;
        if (index == s.size()) return num;
        swap(s[index], s[parent[index]]);
        return stoi(s);
    }
};

// Another:

class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) return num;
        string s = to_string(num);
        
        int left = -1, right = -1;
        int m = -1, index = -1;
        
        for (int i=s.size()-1;i>=0;--i) {
            if (s[i] > m) {
                m = s[i];
                index = i;
                continue;
            }
            
            if (s[i] < m) {
                left = i;
                right = index;
            }
        }
        
        if (left == -1) return num;
        swap(s[left], s[right]);
        return stoi(s);
    }
};