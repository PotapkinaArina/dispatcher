#include <iostream>
#include <string>
#include <fstream>
#include "Manager.h"
using namespace std;

Manager globalManager;

void Manager::listNames()
{
    ifstream file("profiles.json");
    json data;
    if (file.is_open()) {
        file >> data;
        file.close();
        for (auto& player : data.items()) {
            printf("%s\n", player.key().c_str());
        }
    }
}

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
        if (data.contains(n)) {
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

void Manager::loadProfile(const string& n)
{
    ifstream file("profiles.json");
    json data;
    if (file.is_open()) {
        file >> data;
        file.close();
        if (data.contains(n)) {
            this->name = n;
            this->lastLevel = data[n]["lastLevel"];
        }
    }
}
