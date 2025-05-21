#include <iostream>
#include <string>
#include <fstream>
#include "PlayerProfile.h"
using namespace std;

void PlayerProfile::saveProfile()
{
	json data;
	ifstream file("profiles.json");
	if (file.is_open()) {
		file >> data;
		file.close();
	}

	data[name]["lastLevel"] = lastLevel;


	ofstream outfile("profiles.json");
	outfile << data.dump(4);
	outfile.close();
}

void PlayerProfile::loadProfile(const string& name)
{
    ifstream file("profiles.json");
    json data;
    if (file.is_open()) {
        file >> data;
        file.close();
        if (data.contains(name)) {
            this->name = name;
            this->lastLevel = data[name]["lastLevel"];
        }
        else {
            cout << "Error: Profile not found for player: " << name << endl;
        }
    }
}
