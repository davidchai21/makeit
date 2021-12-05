class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        while (!st.empty() && price >= data[st.top()]) st.pop();
        int index = st.empty() ? -1 : st.top();
        st.push(data.size());
        data.push_back(price);
        return data.size()-1-index;
    }
private:
    vector<int> data;
    stack<int> st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Another:

class StockSpanner {
public:
    StockSpanner() {
        len = 0;
        st.push({-1, 0});
    }
    
    int next(int price) {
        while (st.size() > 1 && st.top().second <= price) st.pop();
        int res = len - st.top().first;
        st.push({len++, price});
        return res;
    }
private:
    // <index, val>
    stack<pair<int, int>> st;
    int len;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// vector as stack:

class StockSpanner {
public:
    StockSpanner() {
        len = 0;
        st.push_back({-1, 0});
    }
    
    int next(int price) {
        while (st.size() > 1 && st.back().second <= price) st.pop_back();
        int res = len - st.back().first;
        st.push_back({len++, price});
        return res;
    }
private:
    // <index, val>
    vector<pair<int, int>> st;
    int len;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Another：

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!st.empty() && st.back().first <= price) {
            res += st.back().second;
            st.pop_back();
        }
        st.push_back({price, res});
        return res;
    }
private:
    vector<pair<int, int>> st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */