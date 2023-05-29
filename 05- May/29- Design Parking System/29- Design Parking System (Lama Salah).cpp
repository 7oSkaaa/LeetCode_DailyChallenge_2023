// Author: Lama Salah

class ParkingSystem {
    // A vector to store the number of available parking spaces for each car type.
    vector<int> Parking; 

public:
    ParkingSystem(int big, int medium, int small) {
        // Initialize the vector with the provided parking space counts.
        Parking = vector<int>() = {big, medium, small}; 
    }
    
    bool addCar(int carType) {
        // Check if there are available parking spaces for the specified car type.
        // If so, decrement the number of available spaces and return true.
        // Otherwise, return false.
        return Parking[carType - 1] > 0 ? true, Parking[carType - 1]-- : false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small); // Create a new ParkingSystem object with specified parking space counts
 * bool param_1 = obj->addCar(carType); // Add a car of the specified type and check if it was successfully parked
 */
