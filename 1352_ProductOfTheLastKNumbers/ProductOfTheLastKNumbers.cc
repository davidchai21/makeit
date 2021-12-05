class ProductOfNumbers {
public:
    ProductOfNumbers() {
        record.push_back({1, 0});
    }
    
    void add(int num) {
        if (num) record.push_back({record.back().first*num, record.back().second});
        else record.push_back({1, record.back().second+1});
    }
    
    int getProduct(int k) {
        pair<int, int>& p = record[record.size()-k-1];
        if (record.back().second > p.second) return 0;
        return record.back().first/p.first;
    }
private:
    vector<pair<int, int>> record;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

// Better space:

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        record.push_back(1);
    }
    
    void add(int num) {
        if (num) record.push_back(record.back()*num);
        else record.resize(1);
    }
    
    int getProduct(int k) {
        if (k < record.size()) return record.back()/record[record.size()-k-1];
        return 0;
    }
private:
    vector<int> record;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */