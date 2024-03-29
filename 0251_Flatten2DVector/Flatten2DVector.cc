class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) {
        s = vec.begin();
        e = vec.end();
        if (s != e) it = s->begin();
    }
    
    int next() {
        hasNext();
        return *it++;
    }
    
    bool hasNext() {
        while (s != e && it == s->end()) {
            ++s;
            if (s != e) it = s->begin();
        }
        return s != e;
    }
private:
    vector<vector<int>>::iterator s, e;
    vector<int>::iterator it;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */