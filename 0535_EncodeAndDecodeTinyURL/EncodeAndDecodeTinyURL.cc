class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = tinyURL_prefix + getKey();
        m[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
private:
    const string dic = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t size = 62;
    const string tinyURL_prefix = "http://tinyurl.com/";
    unordered_map<string, string> m;
    
    string getKey() {
        string key = "";
        do {
            key = "";
            for (int i=0;i<8;++i) {
                key.push_back(dic[rand()%size]);
            }
        } while (m.find(key) != m.end());
        return key;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));