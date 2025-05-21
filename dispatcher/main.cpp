#include <iostream>
#include <vector>
#include "../include/json.hpp"
#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"
#include "LevelManager.h"

void printInfo(const Airport& airport) {
	std::cout << "Number of runways: " << airport.getRunwayCount() << endl;
	std::cout << "Number of taxiways: " << airport.getTaxiwayCount() << endl;

	for (const auto& runway : airport.getAllRunways()) {
		std::cout << "Runway #" << runway.getId()
			<< ": length=" << runway.getLength() << "m, "
			<< "direction=" << static_cast<int>(runway.getDirection()) << " degree, "
			<< (runway.isAvailableNow() ? "free" : "busy") << endl;
	}
}

int main()
{
	LevelManager manager;

	vector<Airplane* > planes;
	planes.push_back(new SmallPlane());
	planes.push_back(new MediumPlane());
	planes.push_back(new TrainingPlane());

	for (int i = 0; i < planes.size(); i++)
	{
		planes[i]->printInfo();
		cout << endl;
	}

	Airport airport(true);
	printInfo(airport);
	airport.addRunway(4, 4000, RunwayDirection::WEST);
	// Это тест ВПП с существующим ID
	airport.addRunway(2, 1500, RunwayDirection::NORTH);
	Airport emptyAirport(false);
	printInfo(emptyAirport);
}