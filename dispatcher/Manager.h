#pragma once
#include <string>
#include "../include/json.hpp"
using namespace std;
using json = nlohmann::json;

class Manager {
public:
	Manager() {}

	string getPlayerName() { return name; }
	int getLastLevel() { return lastLevel; }
	void setLastLevel(int level) { lastLevel = level; }

	void createProfile(const string& n);
	bool findProfile(const string& n);
	void saveProfile();
	void loadProfile(const string& n);
private:
	string name;
	int lastLevel;
	json currentLevel;
};

extern Manager globalManager;
