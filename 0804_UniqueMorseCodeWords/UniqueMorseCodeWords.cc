class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for (string& word : words) {
            s.insert(helper(word));
        }
        return s.size();
    }
private:
    vector<string> dic = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string helper(string& word) {
        string res = "";
        for (char a : word) {
            res += dic[a-'a'];
        }
        return res;
    }
};