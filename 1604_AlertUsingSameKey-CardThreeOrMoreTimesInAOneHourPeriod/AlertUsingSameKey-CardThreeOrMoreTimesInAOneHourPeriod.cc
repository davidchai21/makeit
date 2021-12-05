class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        for (int i=0;i<keyName.size();++i) {
            m[keyName[i]].push_back(parse(keyTime[i]));
        }
        
        vector<string> name_list;
        for (auto it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            int right = 0, left = 0;
            int size = it->second.size();
            while (right < size) {
                while (right < size && it->second[right]-60 <= it->second[left]) ++right;
                if (right-left >= 3) {
                    name_list.push_back(it->first);
                    break;
                }
                ++left;
            }
        }
        sort(name_list.begin(), name_list.end());
        return name_list;
    }
private:
    int parse(string& t) {
        return ((t[0]-'0')*10+(t[1]-'0'))*60+10*(t[3]-'0')+t[4]-'0';
    }
};