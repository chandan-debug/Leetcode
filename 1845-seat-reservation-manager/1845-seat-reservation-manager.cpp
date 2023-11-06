class SeatManager {
public:
    set<int> rs;
    set<int> urs;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            urs.insert(i);
    }
    
    int reserve() {
        int seat = *urs.begin();
        urs.erase(seat);
        rs.insert(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        rs.erase(seatNumber);
        urs.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */