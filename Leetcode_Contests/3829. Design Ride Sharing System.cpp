// A ride sharing system manages ride requests from riders and availability from drivers. Riders request rides, and drivers become available over time. The system should match riders and drivers in the order they arrive.

// Implement the RideSharingSystem class:

// RideSharingSystem() Initializes the system.
// void addRider(int riderId) Adds a new rider with the given riderId.
// void addDriver(int driverId) Adds a new driver with the given driverId.
// int[] matchDriverWithRider() Matches the earliest available driver with the earliest waiting rider and removes both of them from the system. Returns an integer array of size 2 where result = [driverId, riderId] if a match is made. If no match is available, returns [-1, -1].
// void cancelRider(int riderId) Cancels the ride request of the rider with the given riderId if the rider exists and has not yet been matched.


class RideSharingSystem {

private:
    queue<int> riders;
    queue<int> drivers;
    unordered_set<int> activeRiders;
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        activeRiders.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        while(!riders.empty() && activeRiders.count(riders.front())==0){
            riders.pop();
        }
        if(riders.empty() || drivers.empty()){
            return {-1,-1};
        }

        int driverId = drivers.front();
        drivers.pop();
        int riderId = riders.front();
        riders.pop();

        activeRiders.erase(riderId);

        return {driverId,riderId};
    }
    
    void cancelRider(int riderId) {
        activeRiders.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */