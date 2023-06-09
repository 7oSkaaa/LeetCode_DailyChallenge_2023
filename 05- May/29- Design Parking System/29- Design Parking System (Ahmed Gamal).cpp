// Author: Ahmed Gamal

// for this problem, we will implement exactly what the problem asks for
// we will keep track of the number of available slots for each type of cars
// and we will try to park a car of a specific type if there is an available slot
// otherwise, we will return false

class ParkingSystem {
    int limits[3], cnt[3];
public:
    ParkingSystem(int big, int medium, int small) {
        // idx: index of the car type
        int idx = 0;

        // initialize the limits and the number of available slots for each type of cars
        for(auto i : {big, medium, small}) {
            cnt[idx] = 0;
            limits[idx++] = i;
        }
    }
    
    bool addCar(int carType) {
        // decrement the car type to match the index of the array
        --carType;

        // if there is no available slot for this type of cars, return false
        if(limits[carType] == cnt[carType]) {
            return false;
        }

        // otherwise, increment the number of available slots for this type of cars and return true
        return ++cnt[carType];
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */