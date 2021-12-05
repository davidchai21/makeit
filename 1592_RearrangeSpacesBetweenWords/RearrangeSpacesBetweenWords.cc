class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> dic;
        stringstream ss(text);
        string word;
        int len = 0;
        while (ss >> word) {
            dic.push_back(word);
            len += word.size();
        }
        if (dic.size() == 1) {
            return dic.front()+string(text.size()-dic.front().size(), ' ');
        }
        len = (text.size()-len)/(dic.size()-1);
        
        string res = string(text.size(), ' ');
        int index = 0;
        for (int i=0;i<dic.size();++i) {
            for (int j=0;j<dic[i].size();++j) {
                res[index++] = dic[i][j];
            }
            index += len;
        }
        return res;
    }
};