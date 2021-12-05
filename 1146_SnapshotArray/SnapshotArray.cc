class SnapshotArray {
public:
    SnapshotArray(int length) {
        ver = 0;
        for (int i=0;i<length;++i) {
            record[i][ver] = 0;
        }
    }
    
    void set(int index, int val) {
        record[index][ver] = val;
    }
    
    int snap() {
        return ver++;
    }
    
    int get(int index, int snap_id) {
        auto it = record[index].upper_bound(snap_id);
        --it;
        return it->second;
    }
private:
    unordered_map<int, map<int, int>> record;
    int ver;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */