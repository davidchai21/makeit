class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> res(n, false);
        vector<long> count(candiesCount.size());
        count[0]=candiesCount[0];
        for (int i=1;i<candiesCount.size();++i) {
            count[i] = count[i-1]+candiesCount[i];
        }

        int index = 0;
        for (vector<int>& query : queries) {
            int type = query[0];
            int day = query[1];
            int cap = query[2];
            if (count[type]>day && ((long)cap*(day+1)>(type?count[type-1]:0))) res[index] = true;
            ++index;
        }
        return res;
    }
};