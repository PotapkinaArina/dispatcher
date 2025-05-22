#include "Airplane.h"
#include <iostream>
using namespace std;

void Airplane::printInfo() const
{
	string m;
	if (model == PlaneModel::CARGO) m = "Cargo";
	else if (model == PlaneModel::EXTRA) m = "Extra";
	else if (model == PlaneModel::LARGE) m = "Large";
	else if (model == PlaneModel::MEDIUM) m = "Medium";
	else if (model == PlaneModel::MILITARY) m = "Military";
	else if (model == PlaneModel::TRAINING) m = "Trainig";
	else m = "Small";

	string s;
	if (state == PlaneState::COMPLETED) s = "Completed";
	else if (state == PlaneState::CRASHED) s = "Crashed";
	else if (state == PlaneState::IN_OPERATION) s = "In operation";
	else if (state == PlaneState::ON_HOLD) s = "On hold";
	else if (state == PlaneState::WAITING_LANDING) s = "Waiting Landing";
	else s = "Waiting Takeoff";

	string d;
	if (direction == Direction::EAST) d = "East";
	if (direction == Direction::NORTH) d = "North";
	if (direction == Direction::SOUTH) d = "South";
	else d = "West";

	cout << "Plane Model: " << m << endl;
	cout << "Plane State: " << s << endl;
	cout << "Operation time: " << operationTime << endl;
	cout << "Max circles: " << maxCircles << endl;
	cout << "Penalty: " << penalty << endl;
	cout << "Track lenght: " << trackLenght << endl;
	cout << "Direction: " << d << endl;
}
