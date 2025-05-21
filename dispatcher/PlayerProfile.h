#pragma once
#include <vector>
#include <string>
#include "../include/json.hpp"
using namespace std;
using json = nlohmann::json;

class PlayerProfile {
public:
	PlayerProfile(string name) : name(name), lastLevel(1) {}
	string getName() { return name; }
	int getLastLevel() { return lastLevel; }
	void setLastLevel(int level) { lastLevel = level; }
	void saveProfile();
	void loadProfile(const string& name);
private:
	string name;
	int lastLevel;
};
