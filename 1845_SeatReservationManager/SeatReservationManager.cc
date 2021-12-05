class SeatManager {
public:
    SeatManager(int n) {
        for (int i=1;i<=n;++i) seat.insert(i);
    }
    
    int reserve() {
        int res = *seat.begin();
        seat.erase(seat.begin());
        return res;
    }
    
    void unreserve(int seatNumber) {
        seat.insert(seatNumber);
    }
private:
    set<int> seat;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

// Self-Increasing:

class SeatManager {
public:
    SeatManager(int n) {
        number = 1;
    }
    
    int reserve() {
        if (seat.empty()) return number++;
        int res = *seat.begin();
        seat.erase(seat.begin());
        return res;
    }
    
    void unreserve(int seatNumber) {
        seat.insert(seatNumber);
    }
private:
    set<int> seat;
    int number;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */