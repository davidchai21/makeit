class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> record(101, vector<int>());
        for (int i=0;i<nums.size();++i) {
            record[nums[i]].push_back(i);
        }
        vector<int> res(queries.size());
        for (int k=0;k<queries.size();++k) {
            int ans = 100;
            int pre = -1;
            int left = queries[k].front(), right = queries[k].back();
            for (int i=1;i<=100;++i) {
                int d1 = lower_bound(record[i].begin(), record[i].end(), left) - record[i].begin();
                int d2 = upper_bound(record[i].begin(), record[i].end(), right) - record[i].begin();
                if (d1 == d2) continue;
                if (pre != -1) {
                    ans = min(ans, i-pre);
                }
                if (ans == 1) break;
                pre = i;
            }
            res[k] = ans == 100 ? -1 : ans;
        }
        return res;
    }
};

// Prefix:

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> record(n, vector<int>());
        vector<int> dic(101, 0);
        for (int i=0;i<n;++i) {
            ++dic[nums[i]];
            record[i] = dic;
        }
        
        vector<int> res(queries.size());
        vector<int> zero(101, 0);
        for (int i=0;i<queries.size();++i) {
            vector<int>& l = queries[i].front() ? record[queries[i].front()-1] : zero;
            vector<int>& r = record[queries[i].back()];
            int ans = 100;
            int pre = -1;
            for (int k=1;k<101;++k) {
                if (l[k] != r[k]) {
                    if (pre != -1) {
                        ans = min(ans, k-pre);
                    }
                    pre = k;
                }
                if (ans == 1) break;
            }
            res[i] = ans == 100 ? -1 : ans;
        }
        return res;
    }
};