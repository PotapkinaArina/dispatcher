#include <iostream>
#include <string>
#include <fstream>
#include "Manager.h"
using namespace std;

Manager globalManager;

void Manager::createProfile(const string& n)
{
    name = n;
    lastLevel = 1;
    cout << "Player " << n << " created successfully!" << endl;
    globalManager.saveProfile();
}

bool Manager::findProfile(const string& n)
{
    ifstream file("profiles.json");
    json data;
    if (file.is_open()) {
        file >> data;
        file.close();
        if (data.contains(name)) {
            return true;
        }
        else {
            return false;
        }
    }
}

void Manager::saveProfile()
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

void Manager::loadProfile(const string& name)
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
    }
}
