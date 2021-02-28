class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res = 0;
        for (vector<string>& item : items) {
            if (ruleKey == "type") {
                res += ruleValue == item[0];
            } else if (ruleKey == "color") {
                res += ruleValue == item[1];
            } else if (ruleKey == "name") {
                res += ruleValue == item[2];
            }
        }
        return res;
    }
};