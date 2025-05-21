#pragma once
#include <vector>
#include <memory>
#include "Runway.h"
using namespace std;

class Airport {
private:
    vector<Runway> runways;
    vector<int> taxiways;
    // тут должны быть рулежные дорожки, но пока просто ID

public:
    Airport(bool addDefaultRunways = true);
    void addRunway(int id, int length, RunwayDirection dir);
    void addTaxiway(int id);
    Runway* findAvailableRunway(int requiredLength);
    size_t getRunwayCount() const;
    size_t getTaxiwayCount() const;
    const vector<Runway>& getAllRunways() const;
};
