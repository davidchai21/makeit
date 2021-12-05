class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        int res = 0;
        vector<int> count(batchSize, 0);
        for (int& k : groups) {
            int index = k%batchSize;
            if (index == 0) ++res;
            else {
                int rest = batchSize - index;
                if (count[rest]) {
                    --count[rest];
                    ++res;
                } else {
                    ++count[index];
                }
            }
        }
        
        unordered_map<string, int> m;
        return res + dfs(count, 0, batchSize, m);
    }
private:
    string getKey(vector<int>& count) {
        string res = "";
        for (int i=0;i<count.size();++i) {
            if (count[i]) {
                res += to_string(i)+":"+to_string(count[i])+",";
            }
        }
        return res;
    }
    
    int dfs(vector<int>& count, int sum, const int& batchSize, unordered_map<string, int>& m) {
        string key = getKey(count);
        if (m.find(key) != m.end()) return m[key];
        
        int res = 0;
        for (int i=0;i<count.size();++i) {
            if (!count[i]) continue;
            
            int t = sum == 0;
            --count[i];
            t += dfs(count, (sum+i)%batchSize, batchSize, m);
            ++count[i];
            res = max(res, t);
        }
        return m[key] = res;
    }
};