#include "Runway.h"
using namespace std;

Runway::Runway(int id, int length, RunwayDirection dir) 
    : id(id), length(length), direction(dir), isAvailable(true), busyUntil(0) {}

bool Runway::isSuitableFor(int requiredLength) const {
    return length >= requiredLength;
}

bool Runway::isAvailableNow() const {
    return isAvailable && time(nullptr) >= busyUntil;
}

void Runway::occupy(time_t duration) {
    isAvailable = false;
    busyUntil = time(nullptr) + duration;
}

void Runway::release() {
    isAvailable = true;
}

int Runway::getId() const { 
    return id; 
}

int Runway::getLength() const { 
    return length; 
}

RunwayDirection Runway::getDirection() const { 
    return direction; 
}