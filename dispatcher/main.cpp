#include <iostream>
#include <string>
#include <vector>
#include "../include/json.hpp"
#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"
#include "LevelManager.h"
#include "PlayerProfile.h"
using namespace std;

int main() {
	cout << "Welcome to the menu!" << endl;
	cout << "Type command:" << endl;
	cout << "Players - to choose player" << endl;
	cout << "Create player - to create player" << endl;
	cout << "Exit - to exit the game" << endl;
	cout << '\n';

	string input;
	getline(cin, input);

	if (input == "Players") {
	
		cout << "There is no players now, you need to create one first" << endl;



		cout << "Would you like to load the game? (Yes or No)" << endl;
		string answer;
		getline(cin, answer);
		if (answer == "Yes") cout << "NOTHING HERE" << endl;
		else if (answer == "No") return 0; //will get back to menu
		else cout << "Invalid command" << endl;
	}
	else if (input == "Create player") {
		cout << "Input the name please:" << endl;
		string name;
		getline(cin, name);

		cout << "Would you like to start the game? (Yes or No)" << endl;
		string answer;
		getline(cin, answer);
		if (answer == "Yes") cout << "NOTHING HERE" << endl;
		else if (answer == "No") return 0; //will get back to menu
		else cout << "Invalid command" << endl;
	}
	else if (input == "Exit") return 0;
	else cout << "Invalid command" << endl;
	return 0;
}

#ifdef sample
void printInfo(const Airport& airport) {
	cout << "Number of runways: " << airport.getRunwayCount() << endl;
	cout << "Number of taxiways: " << airport.getTaxiwayCount() << endl;

	for (const auto& runway : airport.getAllRunways()) {
		cout << "Runway #" << runway.getId()
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
#endif