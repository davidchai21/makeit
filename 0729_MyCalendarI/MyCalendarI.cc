class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (events.empty()) {
            events[start] = end;
            return true;
        }
        
        auto it = events.lower_bound(start);
        if (it != events.end() && it->first < end) return false;
        if (it == events.begin()) {
            if (it->first == end) {
                int old_end = it->second;
                events.erase(it);
                events[start] = old_end;
            }
            else events[start] = end;
            return true;
        }
        auto prev = it;
        --prev;
        if (prev->second > start) return false;
        if (prev->second == start) {
            int old_start = prev->first;
            events.erase(prev);
            events[old_start] = end;
        }
        else events[start] = end;
        return true;
    }
private:
    map<int, int> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// Shorter:

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = m.lower_bound(start);
        if (it != m.end() && it->first < end) return false;
        if (it != m.begin() && (--it)->second > start) return false;
        m[start] = end;
        return true;
    }
private:
    map<int,int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */