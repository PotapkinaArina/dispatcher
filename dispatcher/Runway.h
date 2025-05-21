#pragma once
#include <iostream>
#include <ctime>
using namespace std;

enum class RunwayDirection {
    NORTH = 0,
    EAST = 90,
    SOUTH = 180,
    WEST = 270
};

class Runway {
private:
    int id;
    int length;
    RunwayDirection direction;
    bool isAvailable;
    time_t busyUntil;

public:
    Runway(int id, int length, RunwayDirection dir);
    bool isSuitableFor(int requiredLength) const;
    bool isAvailableNow() const;
    void occupy(time_t duration);
    void release();
    int getId() const;
    int getLength() const;
    RunwayDirection getDirection() const;
};