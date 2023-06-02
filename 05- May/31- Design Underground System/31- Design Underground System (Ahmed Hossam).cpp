// Author: Ahmed Hossam

class UndergroundSystem {
public:

    // Map to store the travel details for each station pair
    map<pair<string, string>, pair<int, int>> mp;
    // Hash map to store the check-in details for each person
    unordered_map<int, pair<string, int>> person;

    // Constructor to initialize the data structures
    UndergroundSystem() {
        mp.clear();
        person.clear();
    }

    // Function to record the check-in of a person
    void checkIn(int id, string stationName, int t) {
        person[id] = {stationName, t};
    }

    // Function to record the check-out of a person and calculate the travel duration
    void checkOut(int id, string stationName, int t) {
        // Check if the station pair exists in the map
        if (mp.find({person[id].first, stationName}) == mp.end()) {
            // If not, create a new entry with the travel duration and count set to the current duration and 1 respectively
            mp[{person[id].first, stationName}] = {t - person[id].second, 1};
        } else {
            // If the station pair already exists, update the travel duration and count
            mp[{person[id].first, stationName}].first += t - person[id].second;
            mp[{person[id].first, stationName}].second++;
        }
    }

    // Function to calculate the average travel time between two stations
    double getAverageTime(string startStation, string endStation) {
        // Calculate and return the average travel time by dividing the total duration by the count
        return 1.0 * mp[{startStation, endStation}].first / mp[{startStation, endStation}].second;
    }
};
