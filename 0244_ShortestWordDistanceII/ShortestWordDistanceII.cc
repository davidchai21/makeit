class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i=0;i<words.size();++i) {
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int r = 0, l=0; r<m[word2].size() && l <m[word1].size();) {
            res = min(res, abs(m[word1][l] - m[word2][r]));
            if (m[word1][l] < m[word2][r]) ++l;
            else ++r;
        }
        return res;
    }
private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */