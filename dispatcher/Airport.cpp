#include <iostream> 
#include "Airport.h"
using namespace std;

Airport::Airport(bool addDefaultRunways) {
    if (addDefaultRunways) {
        // Вот это пример базовых впп для аэропорта, но это можно убрать
        addRunway(1, 2500, RunwayDirection::NORTH);  // Основная 
        addRunway(2, 1800, RunwayDirection::SOUTH);  // Вспомогательная 
        addRunway(3, 3200, RunwayDirection::EAST);   // для больших самолетов
        for (int i = 1; i <= 3; ++i) {
            addTaxiway(i);
        }

    }
    else {
        cout << "Empty airport created (no runways)" << endl;
    }
}

void Airport::addRunway(int id, int length, RunwayDirection dir) {
    for (const auto& r : runways) {
        if (r.getId() == id) {
            cerr << "Error: Runway with ID " << id << " exists!" << endl;
            return;
        }
    }
    runways.emplace_back(id, length, dir);
    cout << "Runway #" << id << " added (length: " << length
        << "m, direction: " << static_cast<int>(dir) << ")" << endl;
}

void Airport::addTaxiway(int id) {
    taxiways.push_back(id);
    cout << "Taxiway #" << id << " added" << endl;
}
Runway* Airport::findAvailableRunway(int requiredLength) {
    for (auto& runway : runways) {
        if (runway.isSuitableFor(requiredLength) && runway.isAvailableNow()) {
            return &runway;
        }
    }
    return nullptr;
}

size_t Airport::getRunwayCount() const {
    return runways.size();
}
size_t Airport::getTaxiwayCount() const {
    return taxiways.size();
}
const std::vector<Runway>& Airport::getAllRunways() const {
    return runways;
}