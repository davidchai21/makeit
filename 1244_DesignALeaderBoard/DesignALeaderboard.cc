class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (m.find(playerId) != m.end()) {
            score += m[playerId];
            reset(playerId);
        }
        m[playerId] = score;
        scores.insert(score);
    }
    
    int top(int K) {
        int res = 0;
        for (auto it = scores.rbegin(); it != scores.rend() && K; --K, ++it) {
            res += *it;
        }
        return res;
    }
    
    void reset(int playerId) {
        scores.erase(scores.find(m[playerId]));
        m.erase(playerId);
    }
private:
    multiset<int> scores;
    unordered_map<int,int> m;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

// map + unordered_map:

class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (m.find(playerId) != m.end()) {
            score += m[playerId];
            reset(playerId);
        }
        ++scores[score];
        m[playerId] = score;
    }
    
    int top(int K) {
        int res = 0;
        for (auto it = scores.rbegin(); it != scores.rend() && K > 0; ++it) {
            int size = min(K, it->second);
            K -= size;
            res += size * it->first;
        }
        return res;
    }
    
    void reset(int playerId) {
        if (--scores[m[playerId]] == 0) {
            scores.erase(m[playerId]);
        }
        m.erase(playerId);
    }
private:
    unordered_map<int, int> m;  // id: score
    map<int,int> scores;    // score: user#
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */