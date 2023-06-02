// Author: Lama Salah

class UndergroundSystem {
    // Map to store check-in details: {id, {stationName, t}}.
    map<int, pair<string, double>> checkIns; 

    // Map to store check-out details: {{startStation, endStation}, {totalTime, journeyCount}}.
    map<pair<string, string>, pair<double, double>> checkOuts; 

public:
    UndergroundSystem() {
        checkIns = map<int, pair<string, double>>(); // Initialize checkIns map.
        checkOuts = map<pair<string, string>, pair<double, double>>(); // Initialize checkOuts map.
    }

    void checkIn(int id, string stationName, int t) {
        // Record check-in details for the given id.
        checkIns[id] = {stationName, t}; 
    }

    void checkOut(int id, string stationName, int t) {
        // Retrieve check-in details for the given id.
        auto checkInDetails = checkIns[id]; 

        // Get the current count of journeys between startStation and endStation and increment by 1.
        int cnt = checkOuts[{checkInDetails.first, stationName}].second + 1; 

        // Get the current total time for journeys between startStation and endStation and 
        // add the time difference between check-in and check-out.
        double totalTime = checkOuts[{checkInDetails.first, stationName}].first + (t - checkInDetails.second); 

        // Update the check-out details for the pair of startStation and endStation.
        checkOuts[{checkInDetails.first, stationName}] = {totalTime, cnt}; 
    }

    double getAverageTime(string startStation, string endStation) {
        // Retrieve the check-out details for the given pair of startStation and endStation.
        auto checkOutDetails = checkOuts[{startStation, endStation}]; 

        // Calculate and return the average time by dividing the total time by the number of journeys.
        return checkOutDetails.first / checkOutDetails.second; 
    }
};



/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */