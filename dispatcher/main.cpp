#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "../include/json.hpp"
#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"
#include "Manager.h"

using namespace std;

void clearConsole() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void waitForSeconds(int seconds) {
	time_t start_time = time(nullptr);

	while (difftime(time(nullptr), start_time) < seconds) {
	}
}

int main() {
	string command = "menu";
	string Player = "None";

	while(true)
	{
		if (command == "menu") {
			clearConsole();
			cout << "Welcome to the menu!" << endl;
			cout << "Current player: " << Player << endl;
			cout << endl;
			cout << "Type command:" << endl;
			cout << "Start - to start the game" << endl;
			cout << "Choose player - to choose the game" << endl;
			cout << "Create player - to create player" << endl;
			cout << "Exit - to exit the game" << endl;
			cout << '\n';

			getline(cin, command);
		}

		else if (command == "Start") {
			clearConsole();
			if (Player == "None") {
				cout << "You has to choose player before the start." << endl;
				cout << "Returning back to menu...";
				waitForSeconds(10);
				command = "menu";
			}
			else {
				cout << "Loading the game...";
				waitForSeconds(10);
				//START GAME HERE
			}
		}

		else if (command == "Choose player") {
			clearConsole();

			cout << "Input the name of the player please: ";
			string nickname;
			getline(cin, nickname);
			cout << endl;

			if (globalManager.findProfile(nickname)) {
				globalManager.loadProfile(nickname);
				cout << "Profile of player " << nickname << " was loaded successfully!" << endl;
				Player = nickname;
			}
			else {
				cout << "There is no players with name " << nickname << ", you need to create one first." << endl;
				cout << "Would you like to create a player? (Yes or No)" << endl;

				string answer;
				getline(cin, answer);
				if (answer == "Yes") command = "Create player";
				else if (answer == "No")command = "menu";
				else cout << "Invalid command" << endl;
			}
		}

		else if (command == "Create player") {
			clearConsole();

			cout << "Input the name please: ";
			string nickname;
			getline(cin, nickname);
			cout << endl;

			if (globalManager.findProfile(nickname)) {
				cout << "Player named " << nickname << " already exists!" << endl;
			}

			else {
				globalManager.createProfile(nickname);
				Player = nickname;
			}

			cout << "Would you like to start the game with that profile? (Yes or No)" << endl;
			string answer;
			getline(cin, answer);
			if (answer == "Yes") command = "Start";
			else if (answer == "No")command = "menu";
			else cout << "Invalid command" << endl;
		}

		else if (command == "Exit") return 0;

		else cout << "Invalid command" << endl;
	}
}

#ifdef sample
int main() {

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