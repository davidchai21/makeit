class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size();
        while (left < right) {
            int mid = (left+right+1)/2;
            if (helper(s, p, removable, mid)) left = mid;
            else right = mid-1;
        }
        return left;
    }
private:
    bool helper(string& s, string& p, vector<int>& removable, int k) {
        unordered_set<int> set(removable.begin(), removable.begin()+k);
        int index = 0;
        for (int i=0;i<s.size() && index < p.size();++i) {
            if (s[i] == p[index] && set.find(i) == set.end()) {
                index++;
            }
        }
        return index == p.size();
    }
};

// quicker?

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size();
        while (left < right) {
            int mid = (left+right+1)/2;
            string t = s;
            for (int i=0;i<mid;++i) {
                t[removable[i]] = ' ';
            }
            
            if (helper(t, p)) left = mid;
            else right = mid-1;
        }
        return left;
    }
private:
    bool helper(string& s, string &p) {
        int index = 0;
        for (int i=0;i<s.size() && index<p.size();++i) {
            if (s[i] == p[index]) ++index;
        }
        return index == p.size();
    }
};