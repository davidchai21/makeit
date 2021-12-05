class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1), ss2(sentence2);
        vector<string> book1, book2;
        string word;
        while (ss1 >> word) {
            book1.push_back(word);
        }
        while (ss2 >> word) {
            book2.push_back(word);
        }
        
        if (book1.size() > book2.size()) book1.swap(book2);
        int m = book1.size();
        int n = book2.size();
        int left = 0, right = m-1;
        while (left < m && book1[left] == book2[left]) ++left;
        while (right >= left && book1[right] == book2[n-m+right]) --right;
        return right < left;
    }
};