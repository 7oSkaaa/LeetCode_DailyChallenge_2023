// Author: Ahmed Hossam

class ParkingSystem {
public:

    // Define a vector to store the number of available parking spaces for each car type
    vector < int > carTypes;

    ParkingSystem(int big, int medium, int small) {
        // Initialize the vector with the given number of parking spaces for each car type
        carTypes = { big, medium, small };
    }
    
    bool addCar(int carType) {
        // Decrease the number of available parking spaces for the given car type and check if it's still greater than 0
        return carTypes[--carType]-- > 0;
    }
};
