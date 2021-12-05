class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num : nums) ++m[num];
        vector<pair<int, int>> record;
        for (auto it = m.begin(); it != m.end(); ++it) {
            record.push_back({it->first, it->second});
        }
        sort(record.begin(), record.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.first < rhs.first;
        });
        
        vector<int> res(record.size()+1, 0);
        res[1] = record[0].first * record[0].second;
        for (int i=1;i<record.size();++i) {
            if (record[i].first != record[i-1].first+1) {
                res[i+1] = res[i] + record[i].first * record[i].second;
            } else {
                res[i+1] = max(res[i], res[i-1]+record[i].first * record[i].second);
            }
        }
        return res.back();
    }
};

// Another:

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> record(10001, 0);
        for (int & num : nums) {
            record[num] += num;
        }
        
        int take = 0, skip = 0;
        for (int i=1;i<=10000;++i) {
            int t = record[i] + skip;
            int s = max(skip, take);
            take = t;
            skip = s;
        }
        return max(take, skip);
    }
};