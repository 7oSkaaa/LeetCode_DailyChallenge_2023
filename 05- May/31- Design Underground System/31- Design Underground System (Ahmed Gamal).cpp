// Author: Ahmed Gamal

// we will simulate the process of checking in and out by keeping track of the time in and the time out for each person
// we will also keep track of the number of people who checked in and out from each station

// the average time for a person to travel from a station to another is the total time for all people who traveled from this station to the other station divided by the number of people who traveled from this station to the other station

class UndergroundSystem {
    // fromTo: map from the starting station to a map from the ending station to the total time for all people who traveled from the starting station to the ending station
    // cntFromTo: map from the starting station to a map from the ending station to the number of people who traveled from the starting station to the ending station
    // time_in: vector of pairs of strings and integers to keep track of the time in for each person and the station they checked in from
    map<string, map<string, int>> fromTo, cntFromTo;
    vector<pair<string, int>> time_in;
public:
    UndergroundSystem() {
        // initialize the maps and the vector
        time_in.assign(1e6 + 5, {"", 0});
    }
    
    void checkIn(int id, string stationName, int t) {
        // set the time in for the person with the given id to the given time and the station to the given station
        time_in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        // get the station and the time in for the person with the given id
        auto [from, tim] = time_in[id];

        // add the time for this person to the total time for all people who traveled from the starting station to the ending station
        fromTo[from][stationName] += t - tim;

        // increment the number of people who traveled from the starting station to the ending station
        cntFromTo[from][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        // return the average time for all people who traveled from the starting station to the ending station
        return double(fromTo[startStation][endStation]) / double(cntFromTo[startStation][endStation]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */