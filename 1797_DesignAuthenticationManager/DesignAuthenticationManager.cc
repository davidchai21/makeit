class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        time = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (m.find(tokenId) == m.end() || m[tokenId]+time <= currentTime) return;
        m[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second + time > currentTime) ++res;
        }
        return res;
    }
private:
    unordered_map<string, int> m;
    int time;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */