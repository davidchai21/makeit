class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        index = 0;
        string _t = "";
        helper(characters, combinationLength, _t, 0);
    }
    
    string next() {
        return record[index++];
    }
    
    bool hasNext() {
        return index < record.size();
    }
private:
    vector<string> record;
    int index;
    
    void helper(string& cha, int len, string& t, int pos) {
        if (t.size() == len) {
            record.push_back(t);
            return;
        }
        
        for (int i=pos;i<cha.size();++i) {
            t.push_back(cha[i]);
            helper(cha, len, t, i+1);
            t.pop_back();
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// Bit Manipulation:

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        len = combinationLength;
        num = (1 << characters.size()) - 1;
        cha = characters;
    }
    
    string next() {
        traverse();
        string res = "";
        helper(num, res);
        --num;
        return res;
    }
    
    bool hasNext() {
        traverse();
        return __builtin_popcount(num) == len;
    }
private:
    int num;
    int len;
    string cha;
    
    void helper(int n, string& res) {
        res.resize(len);
        int k=len-1;
        for (int i=cha.size()-1;i>=0;--i) {
            if (n&1) res[k--] = cha[i];
            n >>= 1;
        }
    }
    
    void traverse() {
        while (num && __builtin_popcount(num) != len) --num;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// Knuth Algorithn L:

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        n = characters.size();
        k = combinationLength;
        cha = characters;
        record.resize(k+1);
        for (int i=0;i<k;++i) record[i] = i;
        record[k] = n;
        has_next = true;
    }
    
    string next() {
        string res = getStr();
        int index = k-1;
        while (index >=0 && record[index] == record[index+1]-1) --index;
        if (index < 0) {
            has_next = false;
        } else {
            ++record[index];
            for (int i=index+1;i<k;++i) {
                record[i] = record[index] + i-index;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return this->has_next;
    }
private:
    vector<int> record;
    int n,k;
    string cha;
    bool has_next;
    
    string getStr() {
        string res(k,'x');
        for (int i=0;i<k;++i) {
            res[i] = cha[record[i]];
        }
        return res;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */